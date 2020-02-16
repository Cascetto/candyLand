//
// Created by Emanuele Casciaro on 25/11/2019.
//

#include "Hero.h"


Hero::Hero(float speed, float g) : GameCharacter(speed, *AssetManager::heroTexture, g) {
    setTextureRect(sf::IntRect(0, 0, 80, 65));
}

void Hero::jump() {
        speed.y -= 75;

    }

void Hero::animate() {
        frameCounter++;
        if(frameCounter >= 5)
            frameCounter = 0;
        setTextureRect(sf::IntRect(80 * frameCounter + 400 * revert,0,80,65));
}

void Hero::update() {
    animate();
}

std::shared_ptr<Bullet> Hero::shoot(float time) {
    std::shared_ptr<Bullet> bullet = nullptr;
    if(time - lastTime >= rof){
        bullet = GameFactory::makeBullet(sf::Vector2f(revert == 0 ? 1 : -1, 0), true);
        bullet->setPosition(getPosition());
        bullet->move(getGlobalBounds().width / 2, 0);
        bullet->setScale(0.33f, 0.33f);
        lastTime = time;
    }
    return bullet;
}

void Hero::action(sf::Vector2f heroPos) {

}

void Hero::powerUp() {
    if(rof >= 0.2)
        rof -= 0.01;
}
