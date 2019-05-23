#ifndef FOXTROT_BASE_WORKER_HPP
#define FOXTROT_BASE_WORKER_HPP


#include <memory>
#include <thread>
#include <condition_variable>
#include <boost/lockfree/spsc_queue.hpp>

#include <foxtrot/Event/Event.hpp>
#include <foxtrot/Event/EventMediator.hpp>
#include <foxtrot/Logger.hpp>


namespace fxt
{

template <class DerivedWorker>
class BaseWorker
{
public:
    explicit BaseWorker(EventMediator* mediator, std::condition_variable& external_condition);
    virtual ~BaseWorker();

    bool produce(Event event);
    void process();

    void terminate();

    std::string as_string();

protected:
    EventMediator* m_manager;

private:
    std::condition_variable& m_external_condition;
    std::mutex m_mutex;

    bool m_processing;

    boost::lockfree::spsc_queue<Event, boost::lockfree::capacity<256>> m_queue;

    std::unique_ptr<std::thread> m_process_thread;
};


template <class DerivedWorker>
BaseWorker<DerivedWorker>::BaseWorker(EventMediator* mediator, std::condition_variable& external_condition) :
    m_manager(mediator),
    m_external_condition(external_condition),
    m_processing(true),
    m_process_thread(std::make_unique<std::thread>(
        std::bind(&BaseWorker<DerivedWorker>::process, this)
    ))
{
}


template <class DerivedWorker>
BaseWorker<DerivedWorker>::~BaseWorker()
{
}


template <class DerivedWorker>
inline bool BaseWorker<DerivedWorker>::produce(Event event)
{
    return m_queue.push(event);
}


template <class DerivedWorker>
inline void BaseWorker<DerivedWorker>::process()
{
    while(m_processing)
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_external_condition.wait(locker,
            [this]()
            {
                return m_queue.read_available();
            }
        );

        m_queue.consume_all(
            [this](Event event)
            {
                static_cast<DerivedWorker*>(this)->consume(event);
                LOGGER_CORE_TRACE("{0} consumed by {1};", event, as_string());
            }
        );
    }

    m_queue.consume_all(
        [this](Event event)
        {
            static_cast<DerivedWorker*>(this)->consume(event);
            LOGGER_CORE_TRACE("Remaining {0} consumed by {1};", event, as_string());
        }
    );
}


template <class DerivedWorker>
inline void BaseWorker<DerivedWorker>::terminate()
{
    m_processing = false;
    m_process_thread->join();
}


template <class DerivedWorker>
inline std::string BaseWorker<DerivedWorker>::as_string()
{
    return static_cast<DerivedWorker*>(this)->get_type();
}


#define WORKER_TYPE(type) \
    inline const char* get_type() \
    { \
        return #type; \
    }

} // namespace fxt

#endif // FOXTROT_BASE_WORKER_HPP
