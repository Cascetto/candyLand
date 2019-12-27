//
// Created by Emanuele Casciaro on 29/11/2019.
//

#ifndef ISANGRYREVISED_OBSERVER_H
#define ISANGRYREVISED_OBSERVER_H


class Observer {
public:
    virtual void update() = 0;

protected:
    virtual ~Observer() = default;
};


#endif //ISANGRYREVISED_OBSERVER_H
