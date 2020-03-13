//
// Created by Emanuele Casciaro on 24/02/2020.
//

#ifndef ISANGRYREVISED_PAUSESTATE_H
#define ISANGRYREVISED_PAUSESTATE_H


#include "GameState.h"
#include "../../GUI/Menu.h"
#include "../GameEngine.h"

class PauseState : public GameState {
public:
    explicit PauseState(TargetWindow targetWindow, std::vector<sf::Sprite*> prevScreen);
    void handleSyncInput() override;
    void computeFrame() override;
    void drawFrame() override;

private:
    std::unique_ptr<Menu> pauseMenu;
    std::vector<sf::Sprite*> background;
    sf::RectangleShape backgroundRect;

};


#endif //ISANGRYREVISED_PAUSESTATE_H
