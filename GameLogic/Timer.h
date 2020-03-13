//
// Created by Emanuele Casciaro on 29/11/2019.
//

#ifndef ISANGRYREVISED_TIMER_H
#define ISANGRYREVISED_TIMER_H

#include <list>

#include "SFML/Graphics.hpp"
#include "Subject.h"


class Timer : public Subject {
public:
    static Timer& getTimer();

    void registerObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyObservers() const override;
    void clearObservers();
    void check();
    float getMainTime();
    void resetMainTime();
    std::list<Observer*> observerlist;
private:
    static Timer* myTimer;
    Timer() = default;
    sf::Clock clock;
    sf::Clock mainClock;
};


#endif //ISANGRYREVISED_TIMER_H
