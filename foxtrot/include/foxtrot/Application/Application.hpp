#ifndef FOXTROT_APPLICATION_HPP
#define FOXTROT_APPLICATION_HPP


#include <memory>
#include <entt/entity/registry.hpp>
#include <foxtrot/Window/IWindow.hpp>
#include <foxtrot/Application/LayerChain.hpp>


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
    entt::registry m_registry;
    std::unique_ptr<IWindow> m_window;
    LayerChain m_layer_chain;

private:
    Application();
    ~Application();
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;
};

} // namespace fxt

#endif // FOXTROT_APPLICATION_HPP
