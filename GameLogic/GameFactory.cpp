//
// Created by Emanuele Casciaro on 29/11/2019.
//

#include "GameFactory.h"

std::shared_ptr<Bullet> GameFactory::makeBullet(sf::Vector2f direction, bool friendly) {
    auto bullet = std::make_shared<Bullet>(direction, 50, friendly);
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
    //todo set speed
    return enemy;
}

GameCharacter* GameFactory::makeArcher(float gravity) {
    auto enemy = new Archer(gravity);
    return enemy;
}

GameCharacter* GameFactory::makeBoss(float gravity) {
    auto enemy = new Boss(gravity, 500, 2);
    return enemy;
}

GameCharacter* GameFactory::makeWatcher(float gravity) {
    //todo range logic
    auto enemy = new Watcher(1000, gravity);
    return enemy;
}

Platform * GameFactory::makePlatform() {
    auto platform = new Platform();
    return platform;
}