//
// Created by mac on 20/02/20.
//

#include "gtest/gtest.h"
#include "../GameLogic/GameFactory.h"



class FACTORY_SUITE : public ::testing::Test {

protected:
    virtual void SetUp() {
        AssetManager::load();
        AssetManager::setFrames();
    }

    virtual void TearDown() {

    }

};

TEST_F(FACTORY_SUITE, CREATE_BRAWLER){
    auto brawler = GameFactory::makeBrawlewr(100);
    Brawler* converted = dynamic_cast<Brawler*>(brawler);
    ASSERT_NE(converted, nullptr);

}

TEST_F(FACTORY_SUITE, CREATE_ARCHER){
    auto archer = GameFactory::makeArcher(100);
    Archer* converted = dynamic_cast<Archer*>(archer);
    ASSERT_NE(converted, nullptr);
}

TEST_F(FACTORY_SUITE, CREATE_WATCHER){
    auto watcher = GameFactory::makeWatcher(100);
    Watcher* converted = dynamic_cast<Watcher*>(watcher);
    ASSERT_NE(converted, nullptr);

}

TEST_F(FACTORY_SUITE, CREATE_BOSS){
    auto boss = GameFactory::makeBoss(100);
    Boss* converted = dynamic_cast<Boss*>(boss);
    ASSERT_NE(converted, nullptr);
}