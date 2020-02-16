//
// Created by mac on 14/02/20.
//

#include "Boss.h"

Boss::Boss(float gravity, float range, float speed):  GameCharacter(speed, *AssetManager::bossTexture, gravity),Archer(gravity), Brawler(speed,gravity), Watcher(range,gravity){



}

void Boss::action(sf::Vector2f heropos) {
    Watcher::action(heropos);
}

void Boss::update() {
    Watcher::update();
}

void Boss::animate() {
    Watcher::animate();
}
