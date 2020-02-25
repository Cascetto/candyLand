//
// Created by Emanuele Casciaro on 25/11/2019.
//

#include "GameCharacter.h"
#include "../GameLogic/State/PlayState.h"

//TODO fixHeight membro di PlayState

void GameCharacter::fixHeight(float groundLevel) {
    float left = getPosition().x;
    float right = left + getGlobalBounds().width;
    float toe = getPosition().y + getGlobalBounds().height ;
    if(getPosition().y + getGlobalBounds().height >= groundLevel) {
        setPosition(getPosition().x, groundLevel - getGlobalBounds().height);
        speed.y = 0;
    }
    if((toe <= 710 && toe >= 700) && (left > 1500 - getGlobalBounds().width && right < 2000 + getGlobalBounds().width)) {
        speed.y = 0;
        setPosition(left, 700 - getGlobalBounds().height);
    }

}

void GameCharacter::move(sf::Vector2f direction) {
    speed.y += PlayState::gravity * SLEEP_TIME;
    sf::Sprite::move(direction.x * speed.x,direction.y * speed.y);
    if(direction.x > 0) revert = 0;
    else if(direction.x < 0) revert = 1;
}

GameCharacter::GameCharacter(float speed, sf::Texture &texture, float g) : speed(sf::Vector2f(speed,0)), gravity(g) {
    setTexture(texture);

}

GameCharacter::~GameCharacter() {

}

bool GameCharacter::takeDamage() {
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