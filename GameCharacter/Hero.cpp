//
// Created by Emanuele Casciaro on 25/11/2019.
//

#include "Hero.h"


Hero::Hero(float speed, float g) : GameCharacter(speed, *AssetManager::heroTexture, g), currwntAmmo{maxAmmo} {
    setTextureRect(sf::IntRect(0, 0, 80, 65));
    animatorManager.setFrames(*AssetManager::heroFrames);
    animatorManager.setFrameTime(2);
    hitSound.setBuffer(*AssetManager::heroDamage);
    shootSound.setBuffer(*AssetManager::heroShoot);
    jumpSound.setBuffer(*AssetManager::heroJumo);
    powerUpSound.setBuffer(*AssetManager::powerUp);
    reloadSound.setBuffer(*AssetManager::reload);
}

float Hero::getRof() const {
    return rof;
}

void Hero::jump() {
        speed.y -= 75;
        jumpSound.play();

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
        shootSound.play();
    }
    return bullet;
}

Bullet* Hero::action(sf::Vector2f heroPos) {
    reloadSound.play();
    return nullptr;
}

void Hero::powerUp() {
    powerUpSound.play();
    if(rof >= 0.5f)
        rof -= 0.02;
}

void Hero::takeDamage() {
    hitSound.play();
}
