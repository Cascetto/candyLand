//
// Created by Emanuele Casciaro on 17/01/2020.
//

#ifndef ISANGRYREVISED_PLATFORM_H
#define ISANGRYREVISED_PLATFORM_H


#include <SFML/Graphics/Sprite.hpp>
#include "../GameLogic/AssetManager.h"

class Platform : public sf::Sprite{
public:
    Platform();
    float left;
    float right;
    float top;
    void setPosition(float x,float y);




};


#endif //ISANGRYREVISED_PLATFORM_H
