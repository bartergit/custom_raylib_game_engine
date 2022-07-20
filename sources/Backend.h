#pragma once

#include "to_include.h"
#include "raylib.h"
#include "vec/vec.h"

struct Texture;

struct Backend {
    int width;
    int height;
    Backend(int width, int height, const std::string &title);

    void before_draw();

    void after_draw();

    void terminate();

    bool key_down(int key);

    std::optional<Texture> load_texture(const std::string &path);

    vec::Vector2<float> get_input();
};
