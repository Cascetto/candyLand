//
// Created by Emanuele Casciaro on 20/12/2019.
//

#ifndef ISANGRYREVISED_ENEMY_H
#define ISANGRYREVISED_ENEMY_H

#include "../GameCharacter.h"
#include "../../GameLogic/GameEngine.h"

class Enemy : public GameCharacter {
public:

    virtual void action(sf::Vector2f heroPos) = 0;

protected:
    Enemy(float speed, sf::Texture& texture, float g);
};


#endif //ISANGRYREVISED_ENEMY_H
