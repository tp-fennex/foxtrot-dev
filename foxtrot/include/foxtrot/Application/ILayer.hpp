#ifndef FOXTROT_ILAYER_HPP
#define FOXTROT_ILAYER_HPP


#include <vector>
#include <entt/entity/registry.hpp>
#include <foxtrot/Event/Event.hpp>
#include <foxtrot/Window/IWindow.hpp>


namespace fxt
{

class ILayer
{
public:
    virtual ~ILayer() = default;

    virtual bool handle_event(const Event& event) = 0;
    virtual void render(IWindow& window) = 0;

protected:
    std::vector<entt::entity> m_objects;
};

} // namespace fxt

#endif // FOXTROT_ILAYER_HPP
