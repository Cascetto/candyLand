//
// Created by Emanuele Casciaro on 29/11/2019.
//

#include "GameFactory.h"

std::shared_ptr<Bullet> GameFactory::makeBullet(sf::Vector2f direction, bool friendly) {
    auto bullet = std::make_shared<Bullet>(direction, 50, friendly);
    return bullet;
}

GameCharacter* GameFactory::makeEnemy(float gravity) {
    auto enemy = new Brawler(5, 50);
    return enemy;
}