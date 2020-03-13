//
// Created by Emanuele Casciaro on 29/11/2019.
//

#include "GameFactory.h"

Bullet* GameFactory::makeBullet(sf::Vector2f direction, bool friendly) {
    auto bullet = new Bullet(direction, 50, friendly);
    return bullet;
}

GameCharacter* GameFactory::makeBrawlewr(float gravity) {
    auto enemy = new Brawler(3, gravity);
    enemy->scale(0.3f, 0.3f);
    Timer::getTimer().registerObserver(&enemy->getAnimator());
    enemy->setSpeed(sf::Vector2f(static_cast<float>(rand() % 16 + 15) / 10.f, enemy->getSpeed().y));
    return enemy;
}

GameCharacter* GameFactory::makeArcher(float gravity) {
    auto enemy = new Archer(gravity);
    enemy->scale(3, 3);
    Timer::getTimer().registerObserver(&enemy->getAnimator());
    return enemy;
}

GameCharacter* GameFactory::makeBoss(float gravity) {
    auto enemy = new Boss(gravity, 500, 2);
    Timer::getTimer().registerObserver(&enemy->getAnimator());
    return enemy;
}

GameCharacter* GameFactory::makeWatcher(float gravity) {
    auto enemy = new Watcher(1000, gravity);
    enemy->scale(0.6f,0.6f);
    Timer::getTimer().registerObserver(&enemy->getAnimator());
    return enemy;
}

sf::Sprite* GameFactory::makeCandy() {
    auto candy = new sf::Sprite(AssetManager::textures.at("CANDY"));
    candy->scale(0.2, 0.2);
    return candy;
}

Platform* GameFactory::makePlatform() {
    auto platform = new Platform();
    return platform;
}