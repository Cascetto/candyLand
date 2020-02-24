//
// Created by Emanuele Casciaro on 29/11/2019.
//

#ifndef ISANGRYREVISED_SCOREOBSERVER_H
#define ISANGRYREVISED_SCOREOBSERVER_H


class ScoreObserver {
public:
    //+50 punti
    virtual void update() = 0;

protected:
    virtual ~ScoreObserver() = default;
};


#endif //ISANGRYREVISED_SCOREOBSERVER_H
