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
    void animate() override;
    void update() override;
    std::shared_ptr<Bullet> shoot(float time);
    void action(sf::Vector2f heroPos) override;

private:
    float rof = 1.f / 2;
    float lastTime {0};
};


#endif //ISANGRYREVISED_HERO_H
