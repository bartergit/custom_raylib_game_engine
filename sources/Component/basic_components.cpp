#include "basic_components.h"
#include "vec/vec.h"
#include "Sys.h"

DEF_SYS

ComponentTransform::ComponentTransform(vec::Vector2<float> position) : position(position) {}


ComponentTexture::ComponentTexture(const std::string &texture_path) {
    auto full_path = ASSETS_PATH + texture_path;
    auto opt_texture = sys.backend->load_texture(full_path);
    ASSERT(opt_texture.has_value(), "failed to load texture " + full_path);
    texture = opt_texture.value();
    _dimensions = {float(texture.width), float(texture.height)};
}

void ComponentTexture::update() {
    auto position = parent->get_component<ComponentTransform>()->position;
    DrawTexture(texture, anchor.x + position.x, anchor.y + position.y, WHITE);
}

void ComponentTexture::set_dimensions(vec::Vector2<float> dimensions) {
    _dimensions = dimensions;
    texture.width = dimensions.x;
    texture.height = dimensions.y;
}

vec::Vector2<float> ComponentTexture::get_dimensions() {
    return _dimensions;
}

void ComponentTexture::centralize_anchor() {
    anchor.x = -get_dimensions().x / 2;
    anchor.y = -get_dimensions().y / 2;
}


