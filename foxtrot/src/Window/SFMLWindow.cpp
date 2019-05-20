#include "foxtrot/Window/SFMLWindow.hpp"
#include "foxtrot/Logger.hpp"


namespace fxt
{

IWindow* IWindow::create(const WindowProperties& properties)
{
    return new SFMLWindow(properties);
}


SFMLWindow::SFMLWindow(const WindowProperties& properties) :
    m_window(sf::VideoMode(properties.width, properties.height), properties.title)
{
    LOGGER_CORE_INFO("Creating window {0} ({1}, {2})",
        properties.title,
        properties.width,
        properties.height
    );
    m_window.setVerticalSyncEnabled(true);
}


inline void SFMLWindow::clear()
{
    m_window.clear();
}


inline void SFMLWindow::draw(const sf::Drawable& drawable)
{
    m_window.draw(drawable);
}


inline void SFMLWindow::display()
{
    m_window.display();
}


inline bool SFMLWindow::poll_event(Event& event)
{
    sf::Event sfml_event;
    m_window.pollEvent(sfml_event);

    switch(sfml_event.type)
    {
        case sf::Event::Closed:
            event.type = Event::WINDOW_CLOSED;
            return true;
        case sf::Event::Resized:
            event.type = Event::WINDOW_RESIZED;
            event.size.width = sfml_event.size.width;
            event.size.height = sfml_event.size.height;
            return true;
        case sf::Event::KeyPressed:
            event.type = Event::KEY_PRESSED;
            event.key.code = sfml_event.key.code;
            return true;
        case sf::Event::KeyReleased:
            event.type = Event::KEY_RELEASED;
            event.key.code = sfml_event.key.code;
            return true;
        default:
            return false;
    }
}

} // namespace fxt
