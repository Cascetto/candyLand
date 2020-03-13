//
// Created by Emanuele Casciaro on 17/01/2020.
//

#include "Platform.h"

Platform::Platform(): sf::Sprite(AssetManager::textures.at("PLATFORM")), left(0), right(width), top(0) {
    setTextureRect(sf::IntRect(0,0,width,height));
}

void Platform::setPosition(float x, float y) {
    Transformable::setPosition(x, y);
    left = x;
    right = left + width;
    top = y;
}
