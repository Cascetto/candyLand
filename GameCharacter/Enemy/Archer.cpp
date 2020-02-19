//
// Created by Emanuele Casciaro on 30/12/2019.
//

#include "Archer.h"


Archer::Archer(float gravity) : GameCharacter(0, *AssetManager::archerTexture, gravity){
    for (int i = 0; i < 20; i++) {
        frame.emplace_back(sf::IntRect(240 * i ,0,240,439));
    }


}

void Archer::animate() {
    setTextureRect(frame[((frameCounter++) % 5) + revert * 5]);
    if(frameCounter >= 50) frameCounter = 0;

}

void Archer::update() {

}

void Archer::action(sf::Vector2f heroPos) {
    if(heroPos.x - getPosition().x < 0)
        revert = 0;
    else revert = 1;

    auto bullet = std::make_shared<Bullet>(sf::Vector2f(1, 0), 50);
    bullet->setPosition(getPosition());
}
