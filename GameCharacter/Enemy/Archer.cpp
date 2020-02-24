//
// Created by Emanuele Casciaro on 30/12/2019.
//

#include "Archer.h"


Archer::Archer(float gravity) : GameCharacter(0, *AssetManager::archerTexture, gravity){
    for (int i = 0; i < 20; i++) {
        frame.emplace_back(sf::IntRect(240 * i ,0,240,439));
    }
    setTextureRect(sf::IntRect(0, 0, 80, 94));
    lastTime = Timer::getMainTime() + static_cast<float>(rand() % 1001 - 500) / 10000;
    rof = static_cast<float>(rand() % 9 + 6) /  3.f;
}

void Archer::animate() {
    //setTextureRect(frame[((frameCounter++) % 5) + revert * 5]);
    if(frameCounter >= 50) frameCounter = 0;

}


std::shared_ptr<Bullet> Archer::action(sf::Vector2f heroPos) {
    std::shared_ptr<Bullet> bullet = nullptr;
    float time = Timer::getMainTime();
    if(time - lastTime >= rof) {
        sf::Vector2f direction = heroPos - getPosition();
        direction /= sqrtf(powf(direction.x, 2) + powf(direction.y, 2));
        if(direction.x < 0)
            revert = 0;
        else
            revert = 1;
        bullet = std::make_shared<Bullet>(direction, 30);
        bullet->setPosition(getPosition());
        bullet->scale(0.3f, 0.3f),
        lastTime = time;
    }
    return bullet;
}
