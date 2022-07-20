#pragma once

#include <chrono>

struct Timer{
    std::int64_t last;

    void update_last() {
        last = now();
    }

    std::int64_t now() {
        auto s = duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        return s;
    }

    std::int64_t delta_ms() {
        return now() - last;
    }

    float delta() {
        return delta_ms() / 1000.0f;
    }

};
