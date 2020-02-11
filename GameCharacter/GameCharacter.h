//
// Created by Emanuele Casciaro on 25/11/2019.
//

#ifndef ISANGRYREVISED_GAMECHARACTER_H
#define ISANGRYREVISED_GAMECHARACTER_H


#include <cmath>
#include "SFML/Graphics.hpp"
#include "../GameLogic/Observer.h"

class GameCharacter : public sf::Sprite, public Observer {
public:
    void fixHeight(float groundLevel);
    virtual void move(sf::Vector2f direction);
    int revert{0};
    bool takeDamage();
    virtual void action(sf::Vector2f heroPos) = 0;

protected:
    GameCharacter(float speed, sf::Texture& texture, float g);
    ~GameCharacter() override;
    sf::Vector2f speed;
public:
    const sf::Vector2f &getSpeed() const;

    void setSpeed(const sf::Vector2f &speed);

protected:
    virtual void animate() = 0;
    int frameCounter {0};

private:
    const float gravity;
};


#endif //ISANGRYREVISED_GAMECHARACTER_H
