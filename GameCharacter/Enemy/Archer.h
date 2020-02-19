//
// Created by Emanuele Casciaro on 30/12/2019.
//

#ifndef ISANGRYREVISED_ARCHER_H
#define ISANGRYREVISED_ARCHER_H


#include "../GameCharacter.h"
#include "../../GameObjects/Bullet.h"

class Archer :  virtual public GameCharacter {

public:
    Archer(float gravity);
    void animate() override;
    void update() override;
    void action(sf::Vector2f heroPos) override;
private:
    std::vector<sf::IntRect> frame;
};


#endif //ISANGRYREVISED_ARCHER_H
