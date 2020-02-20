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

std::shared_ptr<Bullet> Archer::action(sf::Vector2f heroPos) {
    sf::Vector2f direction(-1, 0);
    if(heroPos.x - getPosition().x >= 0)
        direction.x = 1;
    auto bullet = std::make_shared<Bullet>(direction, 50);
    bullet->setPosition(getPosition());
    return bullet;
}
