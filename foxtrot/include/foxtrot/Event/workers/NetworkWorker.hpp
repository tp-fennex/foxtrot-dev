#ifndef FOXTROT_NETWORK_WORKER_HPP
#define FOXTROT_NETWORK_WORKER_HPP


#include "foxtrot/Event/workers/BaseWorker.hpp"


namespace fxt
{

class NetworkWorker : public BaseWorker<NetworkWorker>
{
public:
    WORKER_TYPE(NetworkWorker);

    NetworkWorker(EventMediator* mediator, std::condition_variable& external_condition);

    void consume(Event event);
    void recv_event();

    void terminate_recv_event_thread();

private:
    int m_socket;
    bool m_receiving;
    std::unique_ptr<std::thread> m_recv_event_thread;

private:
    void connect_to(const char* address, unsigned short port);
};

} // namespace fxt

#endif // FOXTROT_NETWORK_WORKER_HPP
