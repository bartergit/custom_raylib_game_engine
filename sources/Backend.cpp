#include "Backend.h"

Backend::Backend(int width, int height, const std::string &title) : width(width), height(height) {
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);
}

void Backend::before_draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void Backend::after_draw() {
    EndDrawing();
}

void Backend::terminate() {
    CloseWindow();
}

bool Backend::key_down(int key) {
    return IsKeyDown(key);
}

std::optional<Texture> Backend::load_texture(const std::string &path) {
    auto full_path = ASSETS_PATH + path;
    auto texture = LoadTexture(path.c_str());
    if (texture.width != 0)
        return texture;
    return {};
}

vec::Vector2<float> Backend::get_input() {
    float x = -key_down(KEY_LEFT) + key_down(KEY_RIGHT);
    float y = key_down(KEY_DOWN) - key_down(KEY_UP);
    return {x, y};
}
