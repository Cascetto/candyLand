//
// Created by Emanuele Casciaro on 30/12/2019.
//

#include "Archer.h"


Archer::Archer(float gravity) : GameCharacter(0, *AssetManager::archerTexture, gravity){
}

void Archer::animate() {

}

void Archer::update() {

}

void Archer::action(sf::Vector2f heroPos) {
    auto bullet = std::make_shared<Bullet>(sf::Vector2f(1, 0), 50);
    bullet->setPosition(getPosition());
}
