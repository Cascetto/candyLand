//
// Created by Emanuele Casciaro on 23/11/2019.
//

#ifndef ISANGRYREVISED_ASSETMANAGER_H
#define ISANGRYREVISED_ASSETMANAGER_H


#include <iostream>
#include <memory>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class AssetManager {
public:
    static void load();
    static void setFrames();

    static std::map<std::string, sf::Texture> textures;
    static std::map<std::string, std::vector<sf::IntRect>> frames;
    static std::map<std::string, sf::SoundBuffer> sounds;
    static std::unique_ptr<sf::Font> mainFont;

    virtual ~AssetManager() = 0;


};


#endif //ISANGRYREVISED_ASSETMANAGER_H
