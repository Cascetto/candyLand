//
// Created by Emanuele Casciaro on 24/11/2019.
//

#ifndef ISANGRYREVISED_RECORDSTATE_H
#define ISANGRYREVISED_RECORDSTATE_H


#include "GameState.h"
#include "../GameEngine.h"
#include "RecordInsState.h"

class RecordState : public GameState {
public:
    explicit RecordState(TargetWindow targetWindow);
    void handleSyncInput() override;
    void computeFrame() override;
    void drawFrame() override;
private:
    std::vector<Record> entries;
    std::vector<sf::Text> record;
};

#endif //ISANGRYREVISED_RECORDSTATE_H
