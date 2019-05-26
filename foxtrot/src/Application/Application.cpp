#include <foxtrot/Application/Application.hpp>
#include <foxtrot/Event/EventManager.hpp>


namespace fxt
{

Application::Application() :
    m_running(true),
    m_window(std::unique_ptr<IWindow>(IWindow::create()))
{
}


Application::~Application()
{
}


Application& Application::get_instance()
{
    static Application s_instance;
    return s_instance;
}


void Application::run()
{
    while(m_running)
    {
        m_window->clear();

        Event event;
        if(m_window->poll_event(event))
        {
            m_layer_chain.update_layers(event);
        }

        fxt::EventManager::get_instance().dispatch();

        m_layer_chain.render_layers(*m_window);

        m_window->display();
    }
}


inline void Application::stop()
{
    m_running = false;
}

} // namespace fxt
