#ifndef FOXTROT_NETWORK_WORKER_HPP
#define FOXTROT_NETWORK_WORKER_HPP


#include "foxtrot/Event/workers/BaseWorker.hpp"


namespace fxt
{

class NetworkWorker : public BaseWorker<NetworkWorker>
{
public:
    using BaseWorker<NetworkWorker>::BaseWorker;

    void consume(Event& event);
    void listen();

private:
    int m_socket;
};

} // namespace fxt

#endif // FOXTROT_NETWORK_WORKER_HPP
