//
// Created by Emanuele Casciaro on 05/12/2019.
//

#include "Watcher.h"

Watcher::Watcher(float speed, float g) : Enemy(speed, *AssetManager::watcherTexture, g) {
    setTextureRect(sf::IntRect(0, 0, 680, 472));
    updateRange();
}

void Watcher::animate() {

}

void Watcher::update() {

}

void Watcher::action(sf::Vector2f heroPos) {
    float distance = abs(heroPos.x - getPosition().x);
    if(distance <= range || distance > 5 * range)
        fadeIn();
    else
        fadeOut();
}

void Watcher::updateRange() {
    range = GameEngine::getGameEngine()->getWindow()->getView().getSize().x / 10.f;
}

void Watcher::fadeOut() {
    if(alpha > 30) {
        alpha--;
        setColor(sf::Color(255, 255, 255, alpha));
    }
}

void Watcher::fadeIn() {
    if(alpha < 255) {
        alpha++;
        setColor(sf::Color(255, 255, 255, alpha));
    }
}