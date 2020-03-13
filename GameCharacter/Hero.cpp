//
// Created by Emanuele Casciaro on 25/11/2019.
//

#include "Hero.h"


Hero::Hero(float speed, float g) : GameCharacter(speed, AssetManager::textures.at("HERO"), g), currentAmmo{maxAmmo} {
    setTextureRect(sf::IntRect(0, 0, 80, 65));
    animatorManager.setFrames(AssetManager::frames.at("HERO_FRAMES"));
    animatorManager.setFrameTime(2);
    hitSound.setBuffer(AssetManager::sounds.at("HERO_DAMAGE"));
    shootSound.setBuffer(AssetManager::sounds.at("HERO_SHOOT"));
    jumpSound.setBuffer(AssetManager::sounds.at("HERO_JUMP"));
    powerUpSound.setBuffer(AssetManager::sounds.at("POWER_UP"));
    reloadSound.setBuffer(AssetManager::sounds.at("RELOAD"));
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
    if((time - lastTime >= rof) && (currentAmmo > 0)) {
        bullet = GameFactory::makeBullet(sf::Vector2f(revert == 0 ? 1 : -1, 0), true);
        bullet->setPosition(getPosition());
        bullet->move(getGlobalBounds().width / 2, 0);
        bullet->setScale(0.33f, 0.33f);
        lastTime = time;
        currentAmmo--;
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
