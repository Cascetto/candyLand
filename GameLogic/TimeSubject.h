//
// Created by Emanuele Casciaro on 03/03/2020.
//

#ifndef ISANGRYREVISED_TIMESUBJECT_H
#define ISANGRYREVISED_TIMESUBJECT_H

#include "TimeObserver.h"

class TimeSubject {
public:
    virtual void registerObserver(TimeObserver* o) = 0;
    virtual void removeObserver(TimeObserver* o) = 0;
    virtual void notifyObservers() const = 0;
};

#endif //ISANGRYREVISED_TIMESUBJECT_H
