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
    void registerObserver(Observer* o) override;
    void removeObserver(Observer* o) override ;
    void notifyObservers() const override ;
    void check();
    static float getMainTime();
    static void resetMainTime();
    std::list<Observer*> observerlist;
private:
    sf::Clock clock;
    static sf::Clock mainClock;
};


#endif //ISANGRYREVISED_TIMER_H
