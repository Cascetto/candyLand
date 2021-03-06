 //
// Created by Emanuele Casciaro on 29/11/2019.
//

#ifndef ISANGRYREVISED_GAMEFACTORY_H
#define ISANGRYREVISED_GAMEFACTORY_H

#include <memory>
#include "../GameObjects/Bullet.h"
#include "../GameCharacter/Enemy/Brawler.h"
#include "../GameCharacter/Enemy/Watcher.h"
#include "../GameCharacter/Enemy/Archer.h"
#include "../GameObjects/Platform.h"
#include "../GameCharacter/Enemy/Boss.h"


class GameFactory {
public:
    static Bullet* makeBullet(sf::Vector2f direction, bool friendly = false);
    static GameCharacter* makeWatcher(float gravity);
    static GameCharacter* makeArcher(float gravity);
    static GameCharacter* makeBrawlewr(float gravity);
    static GameCharacter* makeBoss(float gravity);
    static sf::Sprite* makeCandy();
    static Platform* makePlatform();
    virtual ~GameFactory() = 0;
};


#endif //ISANGRYREVISED_GAMEFACTORY_H
