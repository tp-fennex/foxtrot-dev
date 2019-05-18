#ifndef FOXTROT_NETWORK_WORKER_HPP
#define FOXTROT_NETWORK_WORKER_HPP


#include "foxtrot/Event/workers/BaseWorker.hpp"


namespace fxt
{

class NetworkWorker : public BaseWorker<NetworkWorker>
{
public:
    explicit NetworkWorker(EventMediator* mediator);

    void consume(Event event);
    void listen();

private:
    int m_socket;
    std::unique_ptr<boost::thread> m_listen_thread;

private:
    void connect_to(const char* address, unsigned short port);
};

} // namespace fxt

#endif // FOXTROT_NETWORK_WORKER_HPP
