#ifndef FOXTROT_APPLICATION_HPP
#define FOXTROT_APPLICATION_HPP


#include <memory>

#include "foxtrot/Window/IWindow.hpp"


namespace fxt
{

class Application
{
public:
    static Application& get_instance();

    void run();
    void stop();

private:
    bool m_running;
    std::unique_ptr<IWindow> m_window;

private:
    Application();
    ~Application();
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;
};

} // namespace fxt

#endif // FOXTROT_APPLICATION_HPP
