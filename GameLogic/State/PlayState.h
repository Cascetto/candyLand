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
#include "PauseState.h"
#include "RecordInsState.h"
#include <list>
#include <cstdlib>
#include "../../unit_testing/gtest_src/googletest/include/gtest/gtest_prod.h"

#define GAME_SPEED 200

class PlayState : public GameState, public Observer {
public:
    explicit PlayState(TargetWindow targetWindow);
    void handleSyncInput() override;
    void handleControls();
    void computeFrame() override;
    void drawFrame() override;
    static float gravity;
    void updateGame();
    void update() override;
    void clear();
    FRIEND_TEST(COLLISION_SUITE, BULLET_HERO);
    FRIEND_TEST(COLLISION_SUITE, BULLET_ENEMY);
    FRIEND_TEST(COLLISION_SUITE, HERO_ENEMY);

private:
    short int level {1};
    long int score {0};
    bool detectCollision(Bullet* bullet);
    void moveView();

    bool isOutsideLeft(float rightBorder);
    bool isOutsideRight(float leftBorder);

    std::vector<sf::Sprite*> background;
    float groundLevel;
    unsigned point {0};
    std::shared_ptr<Hero> hero;
    std::vector<GameCharacter*> enemies;
    std::vector<Bullet*> bullets;
    void fixHeight();
    std::vector<Platform*> platforms;
    void generate(float startPoint, float endPoint);
    std::vector<sf::Sprite*> candies;
    std::vector<sf::Sprite*> lives;
    std::vector<sf::Sprite*> ammo;
    bool checkBoss();

    sf::Text scoreLabel;

};


#endif
