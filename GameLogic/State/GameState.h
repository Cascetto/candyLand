//
// Created by Emanuele Casciaro on 23/11/2019.
//

#ifndef ISANGRYREVISED_GAMESTATE_H
#define ISANGRYREVISED_GAMESTATE_H


#include <memory>
#include <iostream>

#include "SFML/Graphics.hpp"

typedef std::shared_ptr<sf::RenderWindow> TargetWindow;

class GameState {
public:
    explicit GameState(TargetWindow targetWindow);
    virtual void handleSincInput() = 0;
    virtual void computeFrame() = 0;
    virtual void drawFrame() = 0;

protected:
    TargetWindow targetWindow;

};


#endif //ISANGRYREVISED_GAMESTATE_H
