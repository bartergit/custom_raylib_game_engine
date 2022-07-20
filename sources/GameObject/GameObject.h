#pragma once

#include "to_include.h"
#include "Component/Component.h"

struct Component;

struct GameObj {
    int id;
    std::vector<std::pair<const std::type_info *, Component *>> components;

    GameObj() {
        id = get_unique_id();
    }

    void init();

    void update();

    // TODO: make sure T is derived from Component
    template<typename T>
    T *get_component() {
        auto &desired_type = typeid(T);
        for (auto &[type, comp]: components) {
            if (*type == desired_type) {
                return dynamic_cast<T *>(comp);
            }
        }
        return nullptr;
    }

    template<typename T>
    void add_component(T *component) {
        component->parent = this;
        auto pair = std::make_pair(&typeid(T), dynamic_cast<Component *>(component));
        components.push_back(pair);
    }

    ~GameObj();
};

