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
    static void loadTest();
    static void setFrames();

    static std::unique_ptr<sf::Texture> backgroundTexture;
    static std::unique_ptr<sf::Texture> heroTexture;
    static std::unique_ptr<sf::Texture> watcherTexture;
    static std::unique_ptr<sf::Texture> brawlerTexture;
    static std::unique_ptr<sf::Texture> archerTexture;
    static std::unique_ptr<sf::Texture> coconutTexture;
    static std::unique_ptr<sf::Texture> platformTexture;
    static std::unique_ptr<sf::Texture> bossTexture;
    static std::unique_ptr<sf::Texture> candyTexture;
    static std::unique_ptr<sf::Texture> heartTexture;

    static std::unique_ptr<sf::Font> mainFont;

    static std::unique_ptr<std::vector<sf::IntRect>> heroFrames;
    static std::unique_ptr<std::vector<sf::IntRect>> archerFrames;
    static std::unique_ptr<std::vector<sf::IntRect>> brawlerFrames;
    static std::unique_ptr<std::vector<sf::IntRect>> watcherFrames;
    static std::unique_ptr<std::vector<sf::IntRect>> bossFrames;

    static std::unique_ptr<sf::SoundBuffer> heroJumo;
    static std::unique_ptr<sf::SoundBuffer> heroShoot;
    static std::unique_ptr<sf::SoundBuffer> heroDamage;
    static std::unique_ptr<sf::SoundBuffer> brawlerDamage;
    static std::unique_ptr<sf::SoundBuffer> archerDamage;
    static std::unique_ptr<sf::SoundBuffer> watcherDamage;
    static std::unique_ptr<sf::SoundBuffer> bossDamage;
    static std::unique_ptr<sf::SoundBuffer> enemyShoot;
    static std::unique_ptr<sf::SoundBuffer> powerUp;
    static std::unique_ptr<sf::SoundBuffer> reload;


    virtual ~AssetManager() = 0;


};


#endif //ISANGRYREVISED_ASSETMANAGER_H
