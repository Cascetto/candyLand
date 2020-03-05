//
// Created by Emanuele Casciaro on 05/12/2019.
//

#include "Watcher.h"

Watcher::Watcher(float range, float g) : GameCharacter(0, *AssetManager::watcherTexture, g), range(range) {
    setTextureRect(sf::IntRect(0, 0, 680, 472));
    for (int i = 0; i < 20; i++)
        frame.emplace_back(sf::IntRect(680 * i,0,680,430));
    GameCharacter::lives = 1;
    animatorManager.setFrames(*AssetManager::watcherFrames);
    animatorManager.setFrameTime(1);
}

void Watcher::animate() {
    setTextureRect(frame[((frameCounter++) % 10) + revert * 10]);
        if(frameCounter >= 100) frameCounter = 0;
}

Bullet* Watcher::action(sf::Vector2f heroPos) {
    float distance = heroPos.x - getPosition().x;
    if(distance < 0){
        revert = 0;
        animatorManager.action = Animator::IDLE_BACK;
    }
    else {
        revert = 1;
        animatorManager.action = Animator::IDLE_FRONT;
    }

    float adistance = abs(distance);
    if(adistance <= range)
        fadeIn();
    else
        fadeOut();
    move(sf::Vector2f(0, 1));
    return nullptr;
}

void Watcher::updateRange(float range) {
    this->range = range;
}

void Watcher::fadeOut() {
    if(alpha > 30) {
        alpha -= 5;
        setColor(sf::Color(255, 255, 255, alpha));
    }
}

void Watcher::fadeIn() {
    if(alpha < 251) {
        alpha += 5;
    } else alpha = 255;
    setColor(sf::Color(255, 255, 255, alpha));
}