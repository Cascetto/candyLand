//
// Created by Emanuele Casciaro on 05/12/2019.
//

#ifndef ISANGRYREVISED_WATCHER_H
#define ISANGRYREVISED_WATCHER_H

#include "../../GameLogic/AssetManager.h"
#include "../GameCharacter.h"
#include "../../GameLogic/GameEngine.h"

class Watcher : public GameCharacter {
public:
    Watcher(float speed, float g);
    void animate() override;
    void update() override;
    void action(sf::Vector2f heroPos) override;
    void updateRange();
    void fadeOut();
    void fadeIn();

private:

    float range;
    unsigned short int alpha {255};

};


#endif //ISANGRYREVISED_WATCHER_H
