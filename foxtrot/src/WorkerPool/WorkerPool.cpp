#include <foxtrot/WorkerPool/WorkerPool.hpp>



fxt::WorkerPool::WorkerPool() : m_running(false), m_stop(false)
{

}


fxt::WorkerPool::~WorkerPool()
{
    m_running = false;
    m_stop = true;
    m_queue_cond.notify_all();

    for (auto& thread:m_workers)
    {
        LOGGER_CORE_TRACE("Worker stopped");
        thread.join();
    }
}


void fxt::WorkerPool::start()
{
    size_t threads_num = std::thread::hardware_concurrency();
    if (!threads_num)
    {
        threads_num = 1;
    }

    m_running = true;

    for (size_t i = 0; i < threads_num; ++i)
    {
        LOGGER_CORE_TRACE("Worker started");
        m_workers.emplace_back(std::bind(&WorkerPool::loop, this));
    }
}


void fxt::WorkerPool::loop()
{
    while (m_running)
    {
        {
            std::unique_lock<std::mutex> lock(m_queue_mutex);
            m_queue_cond.wait(lock, [this]{ return !m_jobs_queue.empty() || m_stop; });

            // Check if thread was notified to stop
            if (!m_running)
            {
                return;
            }

            auto job = m_jobs_queue.front();
            m_jobs_queue.pop();

            job(); // move out of context?
        }
    }
}


void fxt::WorkerPool::add_job(std::function<void()> job)
{
    {
        std::unique_lock<std::mutex> lock(m_queue_mutex);
        m_jobs_queue.push(job);
    }
    m_queue_cond.notify_one();
}
