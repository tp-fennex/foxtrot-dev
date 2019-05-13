#ifndef FOXTROT_EVENT_MANAGER_HPP
#define FOXTROT_EVENT_MANAGER_HPP


#include <memory>
#include <boost/lockfree/queue.hpp>

#include "foxtrot/Event/EventMediator.hpp"
#include "foxtrot/Event/workers/NetworkWorker.hpp"


namespace fxt
{

class EventManager : public EventMediator
{
public:
    EventManager();
    virtual ~EventManager();

    virtual bool produce(Event& event) override;
    void dispatch();

    void init_network_worker();
    void term_network_worker();

private:
    boost::lockfree::queue<Event, boost::lockfree::capacity<1024>> m_queue;
    std::unique_ptr<NetworkWorker> m_network_worker;
};

} // namespace fxt

#endif // FOXTROT_EVENT_MANAGER_HPP
