//
// Created by Emanuele Casciaro on 30/12/2019.
//

#ifndef ISANGRYREVISED_ARCHER_H
#define ISANGRYREVISED_ARCHER_H


#include "../GameCharacter.h"
#include "../../GameObjects/Bullet.h"
#include "../../GameLogic/Timer.h"


class Archer : virtual public GameCharacter {
private:
    float rof;
    float lastTime;
public:
    Archer(float gravity);
    Bullet* action(sf::Vector2f heroPos) override;
private:
    std::vector<sf::IntRect> frame;
};


#endif //ISANGRYREVISED_ARCHER_H
