#pragma once

#include <vector>
#include <unordered_map>
#include <optional>
#include <typeindex>
#include <iostream>
#include <memory>
#include <cassert>
#include <cmath>
#include "utility.h"

#define ASSERT(exp, msg) assert(((void)(msg), exp))

#define DEF_SYS extern struct Sys sys;
