#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "foxtrot/Event/EventMediator.hpp"
#include "foxtrot/Event/workers/NetworkWorker.hpp"
#include "foxtrot/Event/proto/event.pb.h"


namespace fxt
{

NetworkWorker::NetworkWorker(EventMediator* mediator, std::condition_variable& external_condition) :
    BaseWorker(mediator, external_condition),
    m_socket(socket(AF_INET, SOCK_STREAM, 0)),
    m_receiving(true),
    m_recv_event_thread(std::make_unique<std::thread>(
        std::bind(&NetworkWorker::recv_event, this)
    ))
{
    struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

    setsockopt(m_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
}


void NetworkWorker::consume(Event event)
{
    switch(event.type)
    {
        case Event::NETWORK_CONNECT:
            connect_to(event.connection.address, event.connection.port);
            return;
        case Event::NETWORK_DISCONNECT:
            close(m_socket);
            return;
        case Event::WORKER_TERMINATE:
            terminate_recv_event_thread();
            return;
        default:
            return;
    }

    ProtoEvent proto_event;
    proto_event.set_type(event.type);

    proto_event.SerializeToFileDescriptor(m_socket);
}


void NetworkWorker::recv_event()
{
    while(m_receiving)
    {
        ProtoEvent proto_event;
        proto_event.ParseFromFileDescriptor(m_socket);
        // std::cout << proto_event.type() << std::endl;
        // Create 'Event event' object from ProtoEvent
        // m_manager->dispatch(event);
    }
}


void NetworkWorker::terminate_recv_event_thread()
{
    m_receiving = false;
    m_recv_event_thread->join();
}


void NetworkWorker::connect_to(const char* address, unsigned short port)
{
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(address);
    server_addr.sin_port = htons(port);

    Event event;

    if(connect(m_socket, (sockaddr*)&server_addr, sizeof(server_addr)))
    {
        event.type = {Event::NETWORK_FAILED};
    }
    else
    {
        event.type = {Event::NETWORK_SUCCESS};
    }

    m_manager->produce(event);
}

} // namespace fxt
