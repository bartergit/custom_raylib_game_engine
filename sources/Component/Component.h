#pragma once

#include "to_include.h"
#include "GameObject/GameObject.h"

struct GameObj;

struct Component {
    GameObj *parent;

    virtual void init() {

    }

    virtual void update() {
    };
};
