#include <iostream>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#include "foxtrot/Event/EventMediator.hpp"
#include "foxtrot/Event/workers/NetworkWorker.hpp"
#include "foxtrot/Event/proto/event.pb.h"


namespace fxt
{

NetworkWorker::NetworkWorker(EventMediator* mediator, std::condition_variable& external_condition) :
    BaseWorker(mediator, external_condition),
    m_socket(socket(AF_INET, SOCK_STREAM, 0)),
    m_listen_thread(std::make_unique<std::thread>(
        std::bind(&NetworkWorker::listen, this)
    ))
{
}


void NetworkWorker::consume(Event event)
{
    ProtoEvent proto_event;
    proto_event.set_type(event.type);

    if(event.type == Event::NETWORK_CONNECT)
    {
        connect_to(event.connection.address, event.connection.port);
        return;
    }
    else if(event.type == Event::NETWORK_DISCONNECT)
    {
        close(m_socket);
        return;
    }

    proto_event.SerializeToFileDescriptor(m_socket);
}


void NetworkWorker::listen()
{
    while(true)
    {
        ProtoEvent proto_event;
        proto_event.ParseFromFileDescriptor(m_socket);
        // std::cout << proto_event.type() << std::endl;
        // Create 'Event event' object from ProtoEvent
        // m_manager->dispatch(event);
    }
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
