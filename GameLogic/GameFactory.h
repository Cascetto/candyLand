//
// Created by Emanuele Casciaro on 29/11/2019.
//

#ifndef ISANGRYREVISED_GAMEFACTORY_H
#define ISANGRYREVISED_GAMEFACTORY_H

#include <memory>
#include "../GameObjects/Bullet.h"
#include "../GameCharacter/Enemy/Brawler.h"

class GameFactory {
public:
    static std::shared_ptr<Bullet> makeBullet(sf::Vector2f direction, bool friendly = false);
    static GameCharacter* makeEnemy(float gravity);
};


#endif //ISANGRYREVISED_GAMEFACTORY_H
