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

} // namespace fxt
