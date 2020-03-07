//
// Created by Emanuele Casciaro on 03/03/2020.
//

#ifndef ISANGRYREVISED_TIMEOBSERVER_H
#define ISANGRYREVISED_TIMEOBSERVER_H


class TimeObserver {
public:
    virtual void update() = 0;

protected:
    virtual ~TimeObserver() = default;
};


#endif //ISANGRYREVISED_TIMEOBSERVER_H
