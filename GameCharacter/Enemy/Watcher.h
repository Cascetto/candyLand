//
// Created by Emanuele Casciaro on 05/12/2019.
//

#ifndef ISANGRYREVISED_WATCHER_H
#define ISANGRYREVISED_WATCHER_H

#include "../../GameLogic/AssetManager.h"
#include "../GameCharacter.h"

class Watcher : virtual public GameCharacter {
public:
    Watcher(float range, float g);
    void animate() override;
    void update() override;
    void action(sf::Vector2f heroPos) override;
    void updateRange(float range);
    void fadeOut();
    void fadeIn();

private:

    float range;
    unsigned short int alpha {255};

};


#endif //ISANGRYREVISED_WATCHER_H
