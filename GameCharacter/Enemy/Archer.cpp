//
// Created by Emanuele Casciaro on 30/12/2019.
//

#include "Archer.h"


Archer::Archer(float gravity) : GameCharacter(0, *AssetManager::archerTexture, gravity){
    for (int i = 0; i < 20; i++) {
        frame.emplace_back(sf::IntRect(240 * i ,0,240,439));
    }
    setTextureRect(sf::IntRect(0, 0, 80, 94));
}

void Archer::animate() {
    //setTextureRect(frame[((frameCounter++) % 5) + revert * 5]);
    if(frameCounter >= 50) frameCounter = 0;

}

void Archer::update() {

}

std::shared_ptr<Bullet> Archer::action(sf::Vector2f heroPos) {
    sf::Vector2f direction(1, 0);
    if(heroPos.x - getPosition().x < 0) {
        revert = 0;
        direction.x = -1;
    } else
        revert = 1;
    auto bullet = std::make_shared<Bullet>(direction, 50);
    bullet->setPosition(getPosition());
    return nullptr;
    return bullet;
}
