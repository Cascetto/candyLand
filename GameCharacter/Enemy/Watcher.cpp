//
// Created by Emanuele Casciaro on 05/12/2019.
//

#include "Watcher.h"

Watcher::Watcher(float range, float g) : GameCharacter(0, *AssetManager::watcherTexture, g), range(range) {
    setTextureRect(sf::IntRect(0, 0, 690, 472));
    for (int i = 0; i < 20; i++)
        frame.emplace_back(sf::IntRect(690 * i,0,690,430));

}

void Watcher::animate() {
    setTextureRect(frame[((frameCounter++) % 10) + revert * 10]);
        if(frameCounter >= 100) frameCounter = 0;
}

void Watcher::update() {

}

std::shared_ptr<Bullet> Watcher::action(sf::Vector2f heroPos) {
    float distance = heroPos.x - getPosition().x;
    if(distance < 0)
        revert = 0;
    else revert = 1;

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