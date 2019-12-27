//
// Created by Emanuele Casciaro on 23/11/2019.
//

#include "Star.h"

Star::Star(float radius, int points) : CircleShape(radius, points) {
    brightness = static_cast<int> (rand() % 50 + 200);
    speed = static_cast<float> ((rand() % 15 + 1))/ 100;
    active = brightness % 2 == 0;
}

bool Star::getActive() const {
    return active;
}

void Star::updateStar(float start, float stop) {
    if(static_cast<int> (rand() % 100) < 25)
        updateBrightness();
    updatePosition(start, stop);
}

void Star::updateBrightness() {
    if (active) {
        if (brightness >= 255) {
            active = false;
            brightness = 254;
        }
        else brightness++;
    } else {
        if (brightness <= 98) {
            active = true;
            brightness = 99  ;
        }
        else brightness--;
    }
    brightness = brightness < 98 ? 98 : brightness;
    this->setFillColor(sf::Color(brightness, brightness, brightness));
}

void Star::updatePosition(float start, float stop) {
    sf::Vector2f pos = getPosition();
    if (pos.x > stop)
        setPosition(start, pos.y);
    else setPosition(pos.x + speed, pos.y);
}

std::vector<std::shared_ptr<Star>> Star::createStars(const std::shared_ptr<sf::RenderWindow> renderWindow, int number) {
    std::vector<std::shared_ptr<Star>> stars;
    for(int i = 0; i < number; i++) {
        float posX = rand() % renderWindow->getSize().x;
        float posY = rand() % renderWindow->getSize().y * 1.25;
        stars.emplace_back(std::make_shared<Star>(rand() % 5 + 1, 7));
        stars[i]->setPosition(posX, posY);
        stars[i]->setFillColor(sf::Color::White);
    }
    return stars;
}
