//
// Created by Emanuele Casciaro on 25/11/2019.
//

#include "Hero.h"


Hero::Hero(float speed, float g) : GameCharacter(speed, *AssetManager::heroTexture, g), currwntAmmo{maxAmmo} {
    setTextureRect(sf::IntRect(0, 0, 80, 65));
    animatorManager.setFrames(*AssetManager::heroFrames);
    animatorManager.setFrameTime(2);
}

float Hero::getRof() const {
    return rof;
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

Bullet* Hero::shoot(float time) {
    Bullet* bullet = nullptr;
    if((time - lastTime >= rof) && (currwntAmmo > 0)) {
        bullet = GameFactory::makeBullet(sf::Vector2f(revert == 0 ? 1 : -1, 0), true);
        bullet->setPosition(getPosition());
        bullet->move(getGlobalBounds().width / 2, 0);
        bullet->setScale(0.33f, 0.33f);
        lastTime = time;
        currwntAmmo--;
    }
    return bullet;
}

Bullet* Hero::action(sf::Vector2f heroPos) {
    return nullptr;
}

void Hero::powerUp() {
    if(rof >= 0.5f)
        rof -= 0.02;
}
