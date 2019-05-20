#include "foxtrot/Application/Application.hpp"
#include "foxtrot/Event/EventManager.hpp"

#include <iostream>
#include <SFML/Graphics.hpp> // needs to be SFML-independent


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
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while(m_running)
    {
        fxt::EventManager::get_instance().dispatch();
        m_window->clear();
        m_window->draw(shape);
        m_window->display();
    }
}


inline void Application::stop()
{
    m_running = false;
}

} // namespace fxt
