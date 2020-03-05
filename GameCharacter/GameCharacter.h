//
// Created by Emanuele Casciaro on 25/11/2019.
//

#ifndef ISANGRYREVISED_GAMECHARACTER_H
#define ISANGRYREVISED_GAMECHARACTER_H


#include <cmath>
#include "SFML/Graphics.hpp"
#include "../GameLogic/ScoreSubject.h"
#include "../GameLogic/TimeObserver.h"
#include "../GameObjects/Bullet.h"

class GameCharacter : public sf::Sprite, public ScoreSubject {
public:
    void fixHeight(float groundLevel);
    virtual void move(sf::Vector2f direction);
    int revert{0};
    bool takeDamage();
    virtual Bullet* action(sf::Vector2f heroPos) = 0;
    const sf::Vector2f &getSpeed() const;
    virtual void animate() = 0;
    void setSpeed(const sf::Vector2f &speed);
    void removeObserver(ScoreObserver *o) override;
    void registerObserver(ScoreObserver *o) override;
    void notifyObservers() const override;
    class Animator : public TimeObserver {
    public:
        explicit Animator(GameCharacter* obj);
        void update() override;
        enum ACTION {
            IDLE_FRONT = 0,
            IDLE_BACK = 1
        } action {IDLE_FRONT};
        void next();
        void setFrames(std::vector<sf::IntRect> frameList);
        void setFrameTime(int frameTime);
    private:
        //1 = 100ms
        //animation time = (frameLength * 0.1 * frametime) secondi
        int frameLength;
        int frameTime {0};
        int activeFrame {0};

        GameCharacter* obj;

        std::vector<sf::IntRect> frames;
    };
    GameCharacter::Animator& getAnimator();

protected:
    GameCharacter(float speed, sf::Texture& texture, float g);
    ~GameCharacter() override;
    sf::Vector2f speed;
    int frameCounter {0};
    unsigned short int lives {2};
    Animator animatorManager;



private:
    const float gravity;
    std::vector<ScoreObserver*> observerList;
};


#endif //ISANGRYREVISED_GAMECHARACTER_H
