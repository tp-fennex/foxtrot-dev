#include "foxtrot/Event/EventManager.hpp"
#include "foxtrot/Logger.hpp"


int main()
{
    fxt::Logger::init();
    LOGGER_CORE_TRACE("Init logger.");

    fxt::EventManager manager;
    manager.init_network_worker();
    LOGGER_CORE_TRACE("Init network worker.");

    fxt::Event event;
    event.type = fxt::Event::NETWORK_CONNECT;
    const char* str = "192.168.43.81";
    std::copy(str, str+16, event.connection.address);

    event.connection.port = 6666;

    manager.produce(event);

    while(true)
    {
        manager.dispatch();
    }
    return 0;
}
