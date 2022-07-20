#include "to_include.h"
#include "GameObject/GameObject.h"
#include "Component/Component.h"
#include "Component/basic_components.h"
#include "Scene.h"
#include "Backend.h"
#include "Reflection.h"
#include "Sys.h"
#include "Timer.h"
#include "Scripts/init_scene.h"

DEF_SYS

int main() {
    sys.backend->init(600, 600, "title");
    init_scene();
    for (auto &object: sys.scene->objects) {
        object->init();
    }
    sys.timer.update_last();
    while (!WindowShouldClose()) {
        sys.backend->before_draw();
        for (auto &object: sys.scene->objects) {
            object->update();
        }
        sys.timer.update_last();
        sys.backend->after_draw();
    }
    sys.backend->terminate();
    return 0;
}
