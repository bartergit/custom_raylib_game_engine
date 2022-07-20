#pragma once

#include "to_include.h"
#include "Component.h"
#include "Backend.h"
#include "vec/vec.h"

struct ComponentTransform : Component {
    vec::Vector2<float> position;

    explicit ComponentTransform(vec::Vector2<float> position);
};

struct ComponentTexture : Component {
    Texture texture;
    vec::Vector2<float> anchor;

    void centralize_anchor();

    void set_dimensions(vec::Vector2<float> dimensions);

    vec::Vector2<float> get_dimensions();

    explicit ComponentTexture(const std::string &texture_path);

    void update() override;

private:
    vec::Vector2<float> _dimensions;
};
