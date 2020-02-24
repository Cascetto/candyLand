//
// Created by Emanuele Casciaro on 29/11/2019.
//

#ifndef ISANGRYREVISED_SCORESUBJECT_H
#define ISANGRYREVISED_SCORESUBJECT_H

#include <memory>

#include "ScoreObserver.h"

class ScoreSubject {
public:
    virtual void registerObserver(ScoreObserver* o) = 0;
    virtual void removeObserver(ScoreObserver* o) = 0;
    virtual void notifyObservers() const = 0;

protected:
    virtual ~ScoreSubject() = default;
};


#endif //ISANGRYREVISED_SCORESUBJECT_H
