//
// Created by Emanuele Casciaro on 25/11/2019.
//

#include "GameCharacter.h"
#include "../GameLogic/State/PlayState.h"

GameCharacter::GameCharacter(float speed, sf::Texture &texture, float g) : speed(sf::Vector2f(speed,0)), gravity(g),
                                                                           animatorManager(GameCharacter::Animator(this)) {
    setTexture(texture);
    shootSound.setBuffer(*AssetManager::enemyShoot);
}

void GameCharacter::move(sf::Vector2f direction) {
    speed.y += PlayState::gravity * SLEEP_TIME;
    sf::Sprite::move(direction.x * speed.x,direction.y * speed.y);
    if(direction.x > 0) {
        revert = 0;
        animatorManager.action = Animator::IDLE_FRONT;
    }
    else if(direction.x < 0) {
        revert = 1;
        animatorManager.action = Animator::IDLE_BACK;
    }
}

GameCharacter::Animator & GameCharacter::getAnimator() {
    return animatorManager;
}

GameCharacter::~GameCharacter() {

}

bool GameCharacter::takeDamage() {
    hitSound.play();
    return --lives == 0;
}

const sf::Vector2f &GameCharacter::getSpeed() const {
    return speed;
}

void GameCharacter::setSpeed(const sf::Vector2f &speed) {
    GameCharacter::speed = speed;
}

void GameCharacter::notifyObservers() const {
    for(auto observer : observerList)
        observer->update();
}

void GameCharacter::removeObserver(ScoreObserver *o) {
    for(int i = 0; i < observerList.size(); i++) {
        if(observerList[i] == o)
            observerList.erase(observerList.begin() + i);
    }
}

void GameCharacter::registerObserver(ScoreObserver *o) {
    bool found = false;
    for(int i = 0; i < observerList.size() && !found; i++) {
        if(observerList[i] == o)
            found = true;
    }
    if(!found)
        observerList.emplace_back(o);
}

GameCharacter::Animator::Animator(GameCharacter* o) : obj(o) {}

void GameCharacter::Animator::update(){
    if(frameTime < frameLength)
        frameTime++;
    else {
        next();
        frameTime = 0;
    }
}

void GameCharacter::Animator::next() {
    if(activeFrame < (frames.size() / 2) - 1)
        activeFrame++;
    else
        activeFrame = 0;
    obj->setTextureRect(frames[activeFrame + (frames.size() / 2) * action]);

}

void GameCharacter::Animator::setFrameTime(int frameTime) {
    frameLength = frameTime;
}

void GameCharacter::Animator::setFrames(std::vector<sf::IntRect> frameList) {
    frames = frameList;
}