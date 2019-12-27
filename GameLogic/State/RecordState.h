//
// Created by Emanuele Casciaro on 24/11/2019.
//

#ifndef ISANGRYREVISED_RECORDSTATE_H
#define ISANGRYREVISED_RECORDSTATE_H


#include "GameState.h"
#include "../GameEngine.h"

class RecordState : public GameState {
public:
    explicit RecordState(TargetWindow targetWindow);
    void handleSincInput() override;
    void computeFrame() override;
    void drawFrame() override;
private:
};

#endif //ISANGRYREVISED_RECORDSTATE_H
