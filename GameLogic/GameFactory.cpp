//
// Created by Emanuele Casciaro on 29/11/2019.
//

#include "GameFactory.h"

Bullet* GameFactory::makeBullet(sf::Vector2f direction, bool friendly) {
    auto bullet = new Bullet(direction, 50, friendly);
    return bullet;
}

GameCharacter* GameFactory::makeEnemy(float gravity) {
    auto enemy = new Watcher(200, 50);
    //auto enemy = new Archer(200, 50);
    enemy->setPosition(1500, 400);
    return enemy;
}

GameCharacter* GameFactory::makeBrawlewr(float gravity) {
    auto enemy = new Brawler(3, gravity);
    enemy->scale(0.3f, 0.3f);
    Timer::getTimer().registerObserver(&enemy->getAnimator());
    //todo set speed
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

Candy* GameFactory::makeCandy() {
    auto candy = new Candy();
    candy->scale(0.2, 0.2);
    return candy;
}

Platform* GameFactory::makePlatform() {
    auto platform = new Platform();
    return platform;
}