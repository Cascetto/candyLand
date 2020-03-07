//
// Created by mac on 22/02/20.
//
#include "gtest/gtest.h"
#include "../GameCharacter/Hero.h"

class HERO_SUITE : public ::testing::Test {

protected:
    virtual void SetUp() {
        AssetManager::loadTest();
        hero = new Hero(5, 1);
    }

    virtual void TearDown() {
        delete hero;
    }

    Hero* hero;

};

TEST_F(HERO_SUITE,CONTROL_JUMP){
    auto speed = hero->getSpeed();
    hero->jump();
    ASSERT_GT(speed.y,hero->getSpeed().y);
    ASSERT_EQ(speed.x, hero->getSpeed().x);
}

TEST_F(HERO_SUITE,CONTROL_SHOOT){
    auto bullet = hero->shoot(hero->getRof()/2);
    ASSERT_EQ( bullet, nullptr);
    hero->move(sf::Vector2f(1, 0));
    bullet = hero->shoot(hero->getRof()*2);
    ASSERT_NE(bullet, nullptr);
    ASSERT_GT(bullet->getComponent().x,0);
    hero->move(sf::Vector2f(-1, 0));
    bullet = hero->shoot(hero->getRof()*4);
    ASSERT_NE(bullet, nullptr);
    ASSERT_LT(bullet->getComponent().x,0);
}