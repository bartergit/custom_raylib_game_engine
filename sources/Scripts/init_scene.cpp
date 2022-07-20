#include "init_scene.h"
#include "to_include.h"
#include "GameObject/GameObject.h"
#include "Component/basic_components.h"
#include "Sys.h"
#include "Scripts/PlayerController.h"

extern struct Sys sys;

void init_scene() {
    auto game_object = new GameObj;
    auto pos = new ComponentTransform(vec::Vector2{50.0f, 100.0f});
    auto texture = new ComponentTexture("test.png");
    sys.scene->add_object(game_object);
    game_object->add_component(pos);
    game_object->add_component(texture);
    game_object->add_component(new PlayerController());
}