//
// Created by Emanuele Casciaro on 13/12/2019.
//

#include "Bullet.h"

Bullet::Bullet(sf::Vector2f direction, float speed, bool f) : sf::Sprite(*AssetManager::coconutTexture),
    component(direction), mag(speed), friendly(f) {}

void Bullet::move() {
    sf::Transformable::move(component * mag);
}

void Bullet::move(float x, float y) {
    sf::Sprite::move(x, y);
}

void Bullet::setPosition(sf::Vector2f position) {
    Sprite::setPosition(position);
}

bool Bullet::isFriendly() {
    return friendly;
}

const sf::Vector2f &Bullet::getComponent() const {
    return component;
}
