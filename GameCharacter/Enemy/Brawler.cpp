//
// Created by Emanuele Casciaro on 05/12/2019.
//

#include "Brawler.h"

Brawler::Brawler(float speed, float g) : GameCharacter(speed, AssetManager::textures.at("BRAWLER"), g) {
    setTextureRect(sf::IntRect(0, 0,579 ,763));
    for (int i = 0; i < 20; i++) {
        frame.emplace_back(sf::IntRect(579 * i ,0,579,763));
    }
    animatorManager.setFrames(AssetManager::frames.at("BRAWLER_FRAMES"));
    animatorManager.setFrameTime(1);
    hitSound.setBuffer(AssetManager::sounds.at("BRAWLER_DAMAGE"));

}


Bullet* Brawler::action(sf::Vector2f heroPos) {
    auto direction = heroPos - getPosition();
    direction = direction /= sqrt(direction.x * direction.x + direction.y * direction.y);
    move(sf::Vector2f(direction.x * speed.x, 0));
    if(direction.x < 0) {
        revert = 0;
        animatorManager.action = Animator::IDLE_FRONT;
    }
    else {
        revert = 1;
        animatorManager.action = Animator::IDLE_BACK;
    }
    return nullptr;
}