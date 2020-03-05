//
// Created by Emanuele Casciaro on 23/11/2019.
//

#include "StateHandler.h"

StateHandler::StateHandler() {

}

void StateHandler::addState(const std::shared_ptr<GameState>& topState) {
    livingStates.push(topState);
}

void StateHandler::removeState() {
    if (!livingStates.empty()) {
        livingStates.pop();
    } else std::cerr << "Stack degli stati vuoto";
}

const std::shared_ptr<GameState>& StateHandler::getState() {
    return livingStates.top();
}