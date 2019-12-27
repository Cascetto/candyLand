//
// Created by Emanuele Casciaro on 25/11/2019.
//

#include "GameCharacter.h"
#include "../GameLogic/State/PlayState.h"


void GameCharacter::fixHeight(float groundLevel) {
    if(getPosition().y + getGlobalBounds().height >= groundLevel) {
        setPosition(getPosition().x, groundLevel - getGlobalBounds().height);
        speed.y = 0;
    }
}

void GameCharacter::move(sf::Vector2f direction) {
    speed.y += PlayState::gravity * SLEEP_TIME;
    //std::cout << "\n" << speed.y;
    sf::Sprite::move(direction.x * speed.x,direction.y * speed.y);
}

GameCharacter::GameCharacter(float speed, sf::Texture &texture, float g) : speed(sf::Vector2f(speed,0)), gravity(g) {
    setTexture(texture);
    GameEngine::getGameEngine()->timer.registerObserver(this);

}

GameCharacter::~GameCharacter() {
    GameEngine::getGameEngine()->timer.removeObserver(this);
}

bool GameCharacter::takeDamage() {
    return true;
}

