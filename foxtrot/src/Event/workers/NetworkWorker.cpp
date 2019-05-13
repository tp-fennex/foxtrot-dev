#include <iostream>

#include "foxtrot/Event/EventMediator.hpp"
#include "foxtrot/Event/workers/NetworkWorker.hpp"
#include "foxtrot/Event/proto/event.pb.h"


namespace fxt
{

void NetworkWorker::consume(Event& event)
{
    ProtoEvent proto_event;
    proto_event.set_type(static_cast<ProtoEvent_event_type>(event.type));

    if(event.type == Event::Test1)
    {
        auto test1_field = proto_event.mutable_test1();
        test1_field->set_message(event.test1.message);
    }
    else if(event.type == Event::Test2)
    {
        auto test2_field = proto_event.mutable_test2();
        test2_field->set_x(event.test2.x);
        test2_field->set_y(event.test2.y);
    }

    proto_event.SerializeToFileDescriptor(m_socket);
}


void NetworkWorker::listen()
{
    while(true)
    {
        ProtoEvent proto_event;
        proto_event.ParseFromFileDescriptor(m_socket);
        std::cout << proto_event.type() << std::endl;
        // Create 'Event event' object from ProtoEvent
        // m_manager->dispatch(event);
    }
}

} // namespace fxt
