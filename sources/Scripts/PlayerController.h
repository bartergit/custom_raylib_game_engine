#pragma once

#include "to_include.h"
#include "Component/Component.h"
#include "Sys.h"
#include "Timer.h"
#include "vec/vec.h"
#include <iomanip>

DEF_SYS

struct PlayerController : Component {
    float move_speed = 100;
    void update() override {
        auto transform = parent->get_component<ComponentTransform>();
        auto input = sys.backend->get_input();
        if (!input.is_zero()) {
//            std::cout << std::setprecision(20) << dt << "\n";
//            std::cout << (input * Timer.delta_ms()).str() << "\n";

            transform->position += input * sys.timer.delta() * move_speed;
        }
    }
};