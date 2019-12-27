//
// Created by Emanuele Casciaro on 29/11/2019.
//

#ifndef ISANGRYREVISED_SUBJECT_H
#define ISANGRYREVISED_SUBJECT_H

#include <memory>

#include "Observer.h"

class Subject {
public:
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() const = 0;

protected:
    virtual ~Subject() = default;
};


#endif //ISANGRYREVISED_SUBJECT_H
