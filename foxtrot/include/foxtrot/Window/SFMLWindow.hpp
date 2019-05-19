#ifndef FOXTROT_SFML_WINDOW_HPP
#define FOXTROT_SFML_WINDOW_HPP


#include <SFML/Graphics.hpp>

#include "foxtrot/Window/IWindow.hpp"


namespace fxt
{

class SFMLWindow : public IWindow
{
public:
    SFMLWindow(const WindowProperties& properties);

    void clear() override;
    void draw(const sf::Drawable& drawable) override;
    void display() override;

private:
    sf::RenderWindow m_window;
};

} // namespace fxt

#endif // FOXTROT_SFML_WINDOW_HPP
