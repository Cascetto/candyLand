//
// Created by Emanuele Casciaro on 17/01/2020.
//

#include "Platform.h"

Platform::Platform(): sf::Sprite(*AssetManager::platformTexture),left(0),right(100),top(0) {
    setTextureRect(sf::IntRect(0,0,100,100));


}

void Platform::setPosition(float x, float y) {
    Transformable::setPosition(x, y);
    left = x;
    right = left + 100;
    top = y;
}
