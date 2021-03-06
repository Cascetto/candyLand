//
// Created by Emanuele Casciaro on 23/11/2019.
//

#include "GameEngine.h"

std::shared_ptr<GameEngine> GameEngine::myGameEngine = nullptr;

GameEngine::GameEngine() : timer(Timer::getTimer()) {
    srand(time(NULL));
}

std::shared_ptr<GameEngine> GameEngine::getGameEngine() {
    if(myGameEngine == nullptr)
        myGameEngine = std::make_shared<GameEngine>();
    return myGameEngine;
}

const std::shared_ptr<sf::RenderWindow>& GameEngine::getWindow() const {
    return gameWindow;
}

StateHandler& GameEngine::getStateHandler() {
    return stateHandler;
}

void GameEngine::init() {
    if(gameWindow == nullptr) {
        gameWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), GAME_NAME);
        gameWindow->setFramerateLimit(FPS);
        stateHandler.addState(std::make_shared<MenuState>(gameWindow));
        AssetManager::load();
        AssetManager::setFrames();
        soundtrack.openFromFile("./Assets/Audio/mainOst.wav");
        soundtrack.setLoop(true);
        soundtrack.play();
    }
}

void GameEngine::start() {
    while (gameWindow->isOpen()) {
        if(gameClock.getElapsedTime().asSeconds() >= SLEEP_TIME) {
            timer.check();

            stateHandler.getState()->handleSyncInput();
            stateHandler.getState()->computeFrame();
            stateHandler.getState()->drawFrame();

            gameWindow->display();

            gameClock.restart();
        }
    }
}


GameEngine::~GameEngine() {
    soundtrack.stop();
}

void GameEngine::playMain() {
    soundtrack.stop();
    soundtrack.openFromFile("./Assets/Audio/mainOst.wav");
    soundtrack.setVolume(0);
    soundtrack.play();
    timer.clearObservers();
}

void GameEngine::playGameOst() {
    soundtrack.stop();
    soundtrack.openFromFile("./Assets/Audio/playOst.wav");
    soundtrack.setPlayingOffset(sf::seconds(2.7f));
    soundtrack.setVolume(33.3f);
    soundtrack.play();
}
