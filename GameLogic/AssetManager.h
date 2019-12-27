//
// Created by Emanuele Casciaro on 23/11/2019.
//

#ifndef ISANGRYREVISED_ASSETMANAGER_H
#define ISANGRYREVISED_ASSETMANAGER_H


#include <iostream>
#include <memory>
#include "SFML/Graphics.hpp"

class AssetManager {
public:
    static void load();
    static std::unique_ptr<sf::Texture> backgroundTexture;
    static std::unique_ptr<sf::Texture> heroTexture;
    static std::unique_ptr<sf::Texture> watcherTexture;
    static std::unique_ptr<sf::Texture> brawlerTexture;
    static std::unique_ptr<sf::Texture> coconutTexture;


};


#endif //ISANGRYREVISED_ASSETMANAGER_H
