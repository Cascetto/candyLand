//
// Created by Emanuele Casciaro on 23/11/2019.
//

#ifndef ISANGRYREVISED_MENUSTATE_H
#define ISANGRYREVISED_MENUSTATE_H


#include "GameState.h"
#include "RecordState.h"
#include "PlayState.h"
#include "../../GameObjects/Star.h"
#include "../../GUI/Menu.h"


class MenuState : public GameState {
public:
    explicit MenuState(TargetWindow targetWindow);
    void handleSyncInput() override;
    void computeFrame() override;
    void drawFrame() override;
private:
    std::vector<std::shared_ptr<Star>> stars;
    Menu menu;
};


#endif //ISANGRYREVISED_MENUSTATE_H
