//
// Created by Emanuele Casciaro on 23/11/2019.
//

#ifndef ISANGRYREVISED_STAR_H
#define ISANGRYREVISED_STAR_H

#include "SFML/Graphics.hpp"

class Star : public sf::CircleShape {
public:
    explicit Star(float radius, int points = 7);
    bool getActive() const;
    void updateStar(float start, float stop);
    static std::vector<std::shared_ptr<Star>> createStars(const std::shared_ptr<sf::RenderWindow> renderWindow, int number = 300);
private:
    void updateBrightness();
    void updatePosition(float start, float stop);

    bool active;
    unsigned short int brightness;
    float speed;

};


#endif //ISANGRYREVISED_STAR_H
