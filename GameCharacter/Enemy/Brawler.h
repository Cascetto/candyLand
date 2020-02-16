//
// Created by Emanuele Casciaro on 05/12/2019.
//

#ifndef ISANGRYREVISED_BRAWLER_H
#define ISANGRYREVISED_BRAWLER_H

#include "../../GameLogic/AssetManager.h"
#include "../GameCharacter.h"

class Brawler :  virtual public GameCharacter {
public:
    Brawler(float speed, float g);
    void animate() override;
    void update() override;
    void action(sf::Vector2f heroPos) override;

};


#endif //ISANGRYREVISED_BRAWLER_H
