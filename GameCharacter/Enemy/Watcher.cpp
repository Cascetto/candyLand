//
// Created by Emanuele Casciaro on 05/12/2019.
//

#include "Watcher.h"

Watcher::Watcher(float range, float g) : GameCharacter(0, *AssetManager::watcherTexture, g), range(range) {
    setTextureRect(sf::IntRect(0, 0, 680, 472));
}

void Watcher::animate() {

}

void Watcher::update() {

}

void Watcher::action(sf::Vector2f heroPos) {
    float distance = abs(heroPos.x - getPosition().x);
    if(distance <= range)
        fadeIn();
    else
        fadeOut();
    move(sf::Vector2f(0, 1));
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