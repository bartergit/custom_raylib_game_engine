#include "GameObject/GameObject.h"
#include "Component/Component.h"

void GameObj::update() {
    for (auto &[_, comp]: components) {
        comp->update();
    }
}

void GameObj::init(){
    for (auto &[_, comp]: components) {
        comp->init();
    }
}

GameObj::~GameObj() {
    for (auto &[_, comp]: components) {
        free(comp);
    }
}

