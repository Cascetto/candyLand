//
// Created by Emanuele Casciaro on 23/11/2019.
//

#ifndef ISANGRYREVISED_GAMEENGINE_H
#define ISANGRYREVISED_GAMEENGINE_H

#include <memory>

#include "SFML/Graphics.hpp"
#include "AssetManager.h"
#include "State/MenuState.h"
#include "State/StateHandler.h"
#include "Timer.h"


#define GAME_NAME "isAngry"
#define FPS 60
#define SLEEP_TIME 1.0f / FPS


class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    static std::shared_ptr<GameEngine> getGameEngine();

    const std::shared_ptr<sf::RenderWindow>& getWindow() const;
    StateHandler& getStateHandler();

    void init();
    void start();
    void stop();

    Timer timer;

    void playMain();
    void playGameOst();

private:
    static std::shared_ptr<GameEngine> myGameEngine;
    StateHandler stateHandler;

    std::shared_ptr<sf::RenderWindow> gameWindow;

    sf::Clock gameClock;
    sf::Music soundtrack;

};


#endif //ISANGRYREVISED_GAMEENGINE_H
