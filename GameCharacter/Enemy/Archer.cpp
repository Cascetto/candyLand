//
// Created by Emanuele Casciaro on 30/12/2019.
//

#include "Archer.h"

std::shared_ptr<std::vector<std::shared_ptr<Bullet>>> Archer::bullets = nullptr;

Archer::Archer(float gravity) : GameCharacter(0, *AssetManager::archerTexture, gravity){
    if(Archer::bullets == nullptr) Archer::bullets = bullets;
}

void Archer::animate() {

}

void Archer::update() {

}

void Archer::action(sf::Vector2f heroPos) {
    auto bullet = std::make_shared<Bullet>(sf::Vector2f(1, 0), 50);
    bullet->setPosition(getPosition());
    bullets->emplace_back(bullet);
}
