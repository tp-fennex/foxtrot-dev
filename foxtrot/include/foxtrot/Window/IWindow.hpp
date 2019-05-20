#ifndef FOXTROT_IWINDOW_HPP
#define FOXTROT_IWINDOW_HPP


#include <string>
#include <SFML/Graphics.hpp> // needs to be SFML-independent

#include "foxtrot/Event/Event.hpp"


namespace fxt
{

struct WindowProperties
{
    std::string title;
    uint width;
    uint height;

    WindowProperties(
        const std::string& _title = "Foxtrot Engine",
        uint _width = 1280,
        uint _height = 720
    ) : title(_title), width(_width), height(_height)
    {
    }
};


class IWindow
{
public:
    static IWindow* create(const WindowProperties& properties = WindowProperties());

    virtual void clear() = 0;
    virtual void draw(const sf::Drawable& drawable) = 0; // needs to be SFML-independent
    virtual void display() = 0;
    virtual bool poll_event(Event& event) = 0;
};

} // namespace fxt

#endif // FOXTROT_IWINDOW_HPP
