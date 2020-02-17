//
// Created by Emanuele Casciaro on 24/11/2019.
//

#ifndef ISANGRYREVISED_PLAYSTATE_H
#define ISANGRYREVISED_PLAYSTATE_H

#include "GameState.h"
#include "../GameEngine.h"
#include "../../GameCharacter/Hero.h"
#include "../../GameObjects/Bullet.h"
#include "../../GameObjects/Platform.h"
#include "../../GameCharacter/Enemy/Boss.h"
#include "../../GameObjects/Candy.h"
#include <list>



#define GAME_SPEED 200

//TODO funzione difficoltà lv = 6 - (5/e((time - score/10))/100)

class PlayState : public GameState {
public:
    explicit PlayState(TargetWindow targetWindow);
    void handleSincInput() override;
    void handleControls();
    void computeFrame() override;
    void drawFrame() override;
    static float gravity;
    void update();



private:
    short int level {1};
    bool detectCollision(std::shared_ptr<Bullet>& bullet);
    void moveView();

    bool isOutside(sf::Vector2f bottomRight);

    std::vector<sf::Sprite> background;
    float groundLevel;
    unsigned point {0};
    std::shared_ptr<Hero> hero;
    std::vector<GameCharacter*> enemies;
    std::vector<std::shared_ptr<Bullet>> bullets;
    void fixHeight();
    std::vector<Platform> platforms;
    void generate(float startPoint);
    std::vector<Candy> candies;

};


#endif //ISANGRYREVISED_PLAYSTATE_H
