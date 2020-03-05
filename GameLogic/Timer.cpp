//
// Created by Emanuele Casciaro on 29/11/2019.
//

#include "Timer.h"

Timer* Timer::myTimer = nullptr;

void Timer::registerObserver(TimeObserver* o) {
    observerlist.emplace_back(o);

}

void Timer::resetMainTime() {
    mainClock.restart();
}

float Timer::getMainTime() {
    return mainClock.getElapsedTime().asSeconds();
}

void Timer::removeObserver(TimeObserver* o) {
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

Timer & Timer::getTimer() {
    if(myTimer == nullptr)
        myTimer = new Timer();
    return *myTimer;
}