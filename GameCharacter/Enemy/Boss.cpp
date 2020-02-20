//
// Created by mac on 14/02/20.
//

#include "Boss.h"

Boss::Boss(float gravity, float range, float speed):  GameCharacter(speed, *AssetManager::bossTexture, gravity),Archer(gravity), Brawler(speed,gravity), Watcher(range,gravity){
    for (int i = 0; i < 20; i++) {
        frame.emplace_back(sf::IntRect(584 * i ,0,584,587));
    }
}

std::shared_ptr<Bullet> Boss::action(sf::Vector2f heropos) {
    Watcher::action(heropos);
    Brawler::action(heropos);
    return Archer::action(heropos);

}

void Boss::update() {
    Watcher::update();
}

void Boss::animate() {
    Watcher::animate();
    setTextureRect(frame[((frameCounter++) % 10) + revert * 10]);
    if(frameCounter >= 100) frameCounter = 0;
}
