#ifndef FOXTROT_BASE_WORKER_HPP
#define FOXTROT_BASE_WORKER_HPP


#include <memory>
#include <boost/lockfree/spsc_queue.hpp>
#include <boost/thread/thread.hpp>

#include "foxtrot/Event/Event.hpp"
#include "foxtrot/Event/EventMediator.hpp"
#include "foxtrot/Logger.hpp"


namespace fxt
{

template <class DerivedWorker>
class BaseWorker
{
public:
    explicit BaseWorker(EventMediator* mediator);
    virtual ~BaseWorker();

    bool produce(Event& event);
    void process();

protected:
    EventMediator* m_manager;

    boost::lockfree::spsc_queue<Event, boost::lockfree::capacity<256>> m_queue;
    std::unique_ptr<boost::thread> m_main_thread;
};


template <class DerivedWorker>
BaseWorker<DerivedWorker>::BaseWorker(EventMediator* mediator) :
    m_manager(mediator),
    m_main_thread(
        std::make_unique<boost::thread>(boost::bind(&BaseWorker<DerivedWorker>::process, this))
    )
{
}


template <class DerivedWorker>
BaseWorker<DerivedWorker>::~BaseWorker()
{
}


template <class DerivedWorker>
inline bool BaseWorker<DerivedWorker>::produce(Event& event)
{
    return m_queue.push(event);
}


template <class DerivedWorker>
inline void BaseWorker<DerivedWorker>::process()
{
    while(true)
    {
        m_queue.consume_all(
            [this](Event& event)
            {
                LOGGER_CORE_TRACE(event);
                static_cast<DerivedWorker*>(this)->consume(event);
            }
        );
    }
}

} // namespace fxt

#endif // FOXTROT_BASE_WORKER_HPP
