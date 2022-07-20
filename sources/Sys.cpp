#include "Sys.h"

Sys::Sys() {
    backend = std::make_unique<Backend>();
    scene = std::make_unique<Scene>();
}

Sys sys;
