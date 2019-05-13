#include "foxtrot/Event/EventManager.hpp"


namespace fxt
{

EventManager::EventManager() :
    m_network_worker(nullptr)
{
}


EventManager::~EventManager()
{
    term_network_worker();
}


inline bool EventManager::produce(Event& event)
{
    return m_queue.push(event);
}


inline void EventManager::dispatch()
{
    m_queue.consume_all(
        [this](Event& event)
        {
            switch(event.type)
            {
                case Event::Test1:
                case Event::Test2:
                    m_network_worker->produce(event);
                    break;
                default:
                    break;
            }
        });
}


void EventManager::init_network_worker()
{
    if(m_network_worker)
    {
        return;
    }

    m_network_worker = std::make_unique<NetworkWorker>(this);
}


void EventManager::term_network_worker()
{
    if(!m_network_worker)
    {
        return;
    }

    m_network_worker.reset(nullptr);
}

} // namespace fxt
