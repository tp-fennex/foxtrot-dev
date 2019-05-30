#ifndef FOXTROT_WORKERPOOL_HPP
#define FOXTROT_WORKERPOOL_HPP


#include <vector>
#include <thread>

#include <functional>

#include <queue>
#include <mutex>
#include <condition_variable>

#include <foxtrot/Logger.hpp>


namespace fxt
{

class WorkerPool
{
public:
    WorkerPool();
    ~WorkerPool();

    void start();
    void add_job(std::function<void()>);

private:
    bool m_running;
    bool m_stop;

    std::vector<std::thread> m_workers;

    std::queue<std::function<void()>> m_jobs_queue;
    std::mutex m_queue_mutex;
    std::condition_variable m_queue_cond;
private:

    void loop();
};

}


#endif //FOXTROT_WORKERPOOL_HPP
