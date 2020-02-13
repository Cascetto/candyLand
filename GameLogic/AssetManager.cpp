//
// Created by Emanuele Casciaro on 23/11/2019.
//

#include "AssetManager.h"

std::unique_ptr<sf::Texture> AssetManager::backgroundTexture = nullptr;
std::unique_ptr<sf::Texture> AssetManager::heroTexture = nullptr;
std::unique_ptr<sf::Texture> AssetManager::watcherTexture = nullptr;
std::unique_ptr<sf::Texture> AssetManager::brawlerTexture = nullptr;
std::unique_ptr<sf::Texture> AssetManager::archerTexture = nullptr;
std::unique_ptr<sf::Texture> AssetManager::coconutTexture = nullptr;
std::unique_ptr<sf::Texture> AssetManager::platformTexture = nullptr;



void AssetManager::load() {
    try {
        backgroundTexture = std::make_unique<sf::Texture>();
        heroTexture = std::make_unique<sf::Texture>();
        watcherTexture = std::make_unique<sf::Texture>();
        brawlerTexture = std::make_unique<sf::Texture>();
        coconutTexture = std::make_unique<sf::Texture>();
        platformTexture = std::make_unique<sf::Texture>();



        backgroundTexture->loadFromFile("../Assets/Images/Background.png");
        heroTexture->loadFromFile("../Assets/Images/isAnimatedFull.png");
        watcherTexture->loadFromFile("../Assets/Images/dino_idle_original.png");
        brawlerTexture->loadFromFile("../Assets/Images/lanter_walk_original.png");
        //archerTexture->loadFromFile("../Assets/Images/archer.png");
        coconutTexture->loadFromFile("../Assets/Images/coconut.png");
        platformTexture->loadFromFile( "../Assets/Images/coconut.png");

    } catch (const std::exception& exception) {
        std::cerr << exception.what() << std::endl;
    }

}