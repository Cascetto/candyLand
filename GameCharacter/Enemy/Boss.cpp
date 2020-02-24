//
// Created by mac on 14/02/20.
//

#include "Boss.h"

Boss::Boss(float gravity, float range, float speed):  GameCharacter(speed, *AssetManager::bossTexture, gravity),Archer(gravity), Brawler(speed,gravity), Watcher(range,gravity){
    for (int i = 0; i < 14; i++) {
        frame.emplace_back(sf::IntRect(835 * i ,0,835,587));
    }
}

std::shared_ptr<Bullet> Boss::action(sf::Vector2f heropos) {
    Watcher::action(heropos);
    Brawler::action(heropos);
    return Archer::action(heropos);

}

void Boss::animate() {
    Watcher::animate();
    setTextureRect(frame[((frameCounter++) % 7) + revert * 7]);
    if(frameCounter >= 140) frameCounter = 0;
}

void Boss::notifyObservers() const {
    GameCharacter::notifyObservers();
    GameCharacter::notifyObservers();
    GameCharacter::notifyObservers();
}
