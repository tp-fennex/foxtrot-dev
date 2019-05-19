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
                    LOGGER_CORE_TRACE("EventManager pushed to {0}: {1}",
                        m_network_worker->as_string(),
                        event
                    );
                    m_network_worker->produce(event);
                    m_network_condition.notify_one();
                    break;
                default:
                    LOGGER_CORE_WARN("EventManager could not dispatch: {0}",
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
    LOGGER_CORE_INFO("Init network worker.");
}


void EventManager::term_network_worker()
{
    if(!m_network_worker)
    {
        return;
    }

    m_network_worker.reset(nullptr);
    LOGGER_CORE_INFO("Term network worker.");
}

} // namespace fxt
