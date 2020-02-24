//
// Created by Emanuele Casciaro on 29/11/2019.
//

#include "Timer.h"

sf::Clock Timer::mainClock = sf::Clock();

void Timer::registerObserver(ScoreObserver* o) {
    observerlist.emplace_back(o);

}

void Timer::resetMainTime() {
    mainClock.restart();
}

float Timer::getMainTime() {
    return mainClock.getElapsedTime().asSeconds();
}

void Timer::removeObserver(ScoreObserver* o) {
    observerlist.remove(o);
}

void Timer::notifyObservers() const {
    for(auto &i : observerlist)
        i->update();
}

void Timer::check() {
    if(clock.getElapsedTime().asMilliseconds() >= 100){
        clock.restart();
        notifyObservers();
    }
}
