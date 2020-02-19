//
// Created by mac on 14/02/20.
//

#ifndef ISANGRYREVISED_BOSS_H
#define ISANGRYREVISED_BOSS_H


#include "Brawler.h"
#include "Archer.h"
#include "Watcher.h"

class Boss :  public Brawler,  public Archer, public Watcher  {
public:
    Boss(float gravity, float range, float speed);
    void action(sf::Vector2f heropos) override;
    void update() override;
    void animate() override;
private:
    std::vector<sf::IntRect> frame;
};


#endif //ISANGRYREVISED_BOSS_H
