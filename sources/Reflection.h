#pragma once

#include "to_include.h"

struct Reflection {
    using Type = std::pair<std::type_index, const char *>;
    std::unordered_map<std::type_index, std::vector<Type>> map = {};

    template<typename K, typename T>
    void expose(const char *name) {
        std::type_index key = typeid(K);
        Type type = {typeid(T), name};
        if (map.contains(key)) {
            map[key].push_back(type);
            return;
        }
        map[key] = {type};
    }

    template<typename K>
    std::vector<Type> get() {
        return map[typeid(K)];;
    }
};