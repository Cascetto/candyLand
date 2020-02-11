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