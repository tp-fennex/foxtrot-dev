#include <core/factories.hpp>
#include <components/Player.hpp>
#include <components/Position.hpp>
#include <components/Sprite.hpp>


entt::entity make_player(entt::registry& registry)
{
    entt::entity id = registry.create();
    registry.assign<Player>(id);
    registry.assign<Position>(id, 0, 0);

    return id;
}
