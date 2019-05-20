#include "foxtrot/Event/EventManager.hpp"


namespace fxt
{

EventManager::EventManager() :
    m_network_worker(nullptr)
{
}


EventManager::~EventManager()
{
}


EventManager& EventManager::get_instance()
{
    static EventManager s_instance;
    return s_instance;
}


inline bool EventManager::produce(Event event)
{
    return m_queue.push(event);
}


void EventManager::dispatch()
{
    m_queue.consume_all(
        [this](Event& event)
        {
            switch(event.type)
            {
                case Event::NETWORK_CONNECT:
                case Event::NETWORK_SUCCESS:
                case Event::NETWORK_DISCONNECT:
                    LOGGER_CORE_TRACE("EventManager produces {0} to {1};",
                        event,
                        m_network_worker->as_string()
                    );
                    m_network_worker->produce(event);
                    m_network_condition.notify_one();
                    break;
                default:
                    LOGGER_CORE_WARN("EventManager could not dispatch {0}",
                       event
                    );
                    break;
            }
        }
    );
}


void EventManager::init_network_worker()
{
    if(m_network_worker)
    {
        return;
    }

    m_network_worker = std::make_unique<NetworkWorker>(this, m_network_condition);

    LOGGER_CORE_INFO("NetworkWorker initialized.");
}


void EventManager::term_network_worker()
{
    if(!m_network_worker)
    {
        return;
    }

    Event term_event;
    term_event.type = Event::WORKER_TERMINATE;
    m_network_worker->produce(term_event);
    m_network_condition.notify_one();
    m_network_worker->terminate();

    LOGGER_CORE_INFO("NetworkWorker terminated.");
}

} // namespace fxt
