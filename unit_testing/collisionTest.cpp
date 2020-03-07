//
// Created by mac on 07/03/20.
//

#include "gtest/gtest.h"
#include "../GameLogic/State/PlayState.h"


class COLLISION_SUITE : public :: testing::Test{
protected:
    virtual void setUp(){
        AssetManager::loadTest();

    };
    virtual void tearDown(){

    };
    PlayState playState = PlayState(std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), "TEST"));

};

TEST_F(COLLISION_SUITE, BULLET_HERO){
         auto bulletNF = new Bullet(sf::Vector2f(1,0),10);
         bulletNF->setPosition(playState.hero->getPosition());
         playState.bullets.emplace_back(bulletNF);
         auto lives = playState.lives.size();
         playState.updateGame();
         ASSERT_LT(playState.lives.size(),lives);
         ASSERT_TRUE(playState.bullets.empty());
         auto bulletF = new Bullet(sf::Vector2f(-1,0),10,true);
         bulletF->setPosition(playState.hero->getPosition());
         playState.bullets.emplace_back(bulletF);
         lives = playState.lives.size();
         playState.updateGame();
         ASSERT_EQ(lives,playState.lives.size());
         ASSERT_FALSE(playState.bullets.empty());

}

TEST_F(COLLISION_SUITE, BULLET_ENEMY){
    playState.groundLevel = 2000;
    playState.enemies.clear();
    auto watcher= GameFactory::makeWatcher(0);
    watcher->setPosition(1000,1000);
    playState.enemies.emplace_back(watcher);
    auto bulletF= new Bullet(sf::Vector2f(-1,0), 0, true);
    bulletF->setPosition(sf::Vector2f(1000,1000));
    playState.bullets.emplace_back(bulletF);
    playState.updateGame();
    ASSERT_TRUE(playState.bullets.empty());
    ASSERT_TRUE(playState.enemies.empty());
    watcher = GameFactory::makeWatcher(0);
    watcher->setPosition(1000,1000);
    playState.enemies.emplace_back(watcher);
    auto bulletNF= GameFactory::makeBullet(sf::Vector2f(1,0));
    bulletNF->setPosition(sf::Vector2f(1000,1000));
    playState.bullets.emplace_back(bulletNF);
    playState.updateGame();
    ASSERT_FALSE(playState.bullets.empty());
    ASSERT_FALSE(playState.enemies.empty());

}

TEST_F(COLLISION_SUITE, HERO_ENEMY){
    playState.enemies.clear();
    auto watcher= GameFactory::makeWatcher(0);
    watcher->setPosition(playState.hero->getPosition());
    playState.enemies.emplace_back(watcher);
    auto lives= playState.lives.size();
    playState.updateGame();
    ASSERT_LT(playState.lives.size(),lives);
    ASSERT_TRUE(playState.enemies.empty());
}