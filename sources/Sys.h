#pragma once

#include "to_include.h"
#include "Reflection.h"
#include "Backend.h"
#include "Scene.h"
#include "Timer.h"

struct Sys {
    Reflection reflection{};
    Timer timer{};
    std::unique_ptr<Backend> backend;
    std::unique_ptr<Scene> scene;

    Sys();
};

