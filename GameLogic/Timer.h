//
// Created by Emanuele Casciaro on 29/11/2019.
//

#ifndef ISANGRYREVISED_TIMER_H
#define ISANGRYREVISED_TIMER_H

#include <list>

#include "SFML/Graphics.hpp"
#include "ScoreSubject.h"


class Timer : public ScoreSubject {
public:
    void registerObserver(ScoreObserver* o) override;
    void removeObserver(ScoreObserver* o) override ;
    void notifyObservers() const override ;
    void check();
    static float getMainTime();
    static void resetMainTime();
    std::list<ScoreObserver*> observerlist;
private:
    sf::Clock clock;
    static sf::Clock mainClock;
};


#endif //ISANGRYREVISED_TIMER_H
