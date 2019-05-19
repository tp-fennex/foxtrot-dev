#include "foxtrot/Logger.hpp"
#include "foxtrot/Event/EventManager.hpp"
#include "foxtrot/Application/Application.hpp"


int main()
{
    fxt::Logger::init();
    LOGGER_CORE_INFO("Init logger.");

    fxt::EventManager::get_instance().init_network_worker();

    fxt::Event event;
    event.type = fxt::Event::NETWORK_CONNECT;
    const char* str = "127.0.0.1";
    std::copy(str, str+16, event.connection.address);
    event.connection.port = 6666;

    fxt::EventManager::get_instance().produce(event);

    fxt::Application::get_instance().run();

    return 0;
}
