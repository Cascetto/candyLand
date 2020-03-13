//
// Created by Emanuele Casciaro on 23/11/2019.
//

#ifndef ISANGRYREVISED_STATEHANDLER_H
#define ISANGRYREVISED_STATEHANDLER_H

#include <iostream>
#include <memory>
#include <stack>

#include "GameState.h"

#include "SFML/Graphics.hpp"

class StateHandler {
public:
    StateHandler();
    void addState(const std::shared_ptr<GameState>& topState);
    void removeState();
    const std::shared_ptr<GameState>& getState();

private:
    std::stack<std::shared_ptr<GameState>> livingStates;

};


#endif //ISANGRYREVISED_STATEHANDLER_H
