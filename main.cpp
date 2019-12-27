#include <iostream>

#include "GameLogic/GameEngine.h"


int main() {
    auto game = GameEngine::getGameEngine();
    game->init();
    game->start();
}