#pragma once

#include "to_include.h"
#include "GameObject/GameObject.h"

struct Scene {
    std::vector<GameObj *> objects{};

    void add_object(GameObj * gameObj);

    std::optional<GameObj *> find(int id) {
        if (id < objects.size() && objects[id] != nullptr)
            return objects[id];
        return {};
    }

    void destroy(int id) {
        free(*find(id));
        assert("should be nullptr" && find(id).has_value());
    }
};

