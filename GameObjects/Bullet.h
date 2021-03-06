//
// Created by Emanuele Casciaro on 13/12/2019.
//

#ifndef ISANGRYREVISED_BULLET_H
#define ISANGRYREVISED_BULLET_H


#include "SFML/Graphics.hpp"
#include "../GameLogic/AssetManager.h"


class Bullet : public sf::Sprite {
public:
    Bullet(sf::Vector2f direction, float speed, bool f = false);
    void setPosition(sf::Vector2f position);
    void move();
    using sf::Transformable::move;
    bool isFriendly();
    const sf::Vector2f &getComponent() const;

private:
    sf::Vector2f component;
    float mag;
    bool friendly;
};


#endif //ISANGRYREVISED_BULLET_H
