//
// Created by mac on 14/02/20.
//

#include "Boss.h"

Boss::Boss(float gravity, float range, float speed):  GameCharacter(speed, AssetManager::textures.at("BOSS"), gravity),Archer(gravity), Brawler(speed,gravity), Watcher(range,gravity){
    for (int i = 0; i < 14; i++) {
        frame.emplace_back(sf::IntRect(835 * i ,0,835,587));
    }
    GameCharacter::lives = 4;
    animatorManager.setFrames(AssetManager::frames.at("BOSS_FRAMES"));
    animatorManager.setFrameTime(2);
    hitSound.setBuffer(AssetManager::sounds.at("BOSS_DAMAGE"));
}

Bullet* Boss::action(sf::Vector2f heropos) {
    Watcher::action(heropos);
    Brawler::action(heropos);
    return Archer::action(heropos);

}


void Boss::notifyObservers() const {
    GameCharacter::notifyObservers();
    GameCharacter::notifyObservers();
    GameCharacter::notifyObservers();
}
