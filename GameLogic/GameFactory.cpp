//
// Created by Emanuele Casciaro on 29/11/2019.
//

#include "GameFactory.h"

std::shared_ptr<Bullet> GameFactory::makeBullet(sf::Vector2f direction, bool friendly) {
    auto bullet = std::make_shared<Bullet>(direction, 50, friendly);
    return bullet;
}

std::shared_ptr<Enemy> GameFactory::makeEnemy(float gravity) {
    auto enemy = std::make_shared<Brawler>(0, gravity);
}