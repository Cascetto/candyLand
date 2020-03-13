//
// Created by Emanuele Casciaro on 25/11/2019.
//

#ifndef ISANGRYREVISED_HERO_H
#define ISANGRYREVISED_HERO_H

#include <memory>

#include "SFML/Graphics.hpp"
#include "GameCharacter.h"
#include "../GameLogic/AssetManager.h"
#include "../GameLogic/Subject.h"
#include "../GameObjects/Bullet.h"
#include "../GameLogic/GameFactory.h"


class Hero : public GameCharacter {
public:
    Hero(float speed, float g);
    void jump();
    Bullet* shoot(float time);
    Bullet* action(sf::Vector2f heroPos) override;
    void powerUp();
    void takeDamage();

    float getRof() const;

    int maxAmmo {6};
    int currentAmmo;

private:
    float rof {1.f / 2};
    float lastTime {0};
    sf::Sound jumpSound;
    sf::Sound powerUpSound;
    sf::Sound reloadSound;
};


#endif //ISANGRYREVISED_HERO_H
