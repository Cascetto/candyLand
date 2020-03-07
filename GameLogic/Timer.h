//
// Created by Emanuele Casciaro on 29/11/2019.
//

#ifndef ISANGRYREVISED_TIMER_H
#define ISANGRYREVISED_TIMER_H

#include <list>

#include "SFML/Graphics.hpp"
#include "TimeSubject.h"


class Timer : public TimeSubject {
public:
    static Timer& getTimer();

    void registerObserver(TimeObserver* o) override;
    void removeObserver(TimeObserver* o) override;
    void notifyObservers() const override;
    void clearObservers();
    void check();
    float getMainTime();
    void resetMainTime();
    std::list<TimeObserver*> observerlist;
private:
    static Timer* myTimer;
    Timer() = default;
    sf::Clock clock;
    sf::Clock mainClock;
};


#endif //ISANGRYREVISED_TIMER_H
