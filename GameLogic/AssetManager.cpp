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
std::unique_ptr<sf::Texture> AssetManager::bossTexture = nullptr;
std::unique_ptr<sf::Texture> AssetManager::candyTexture = nullptr;
std::unique_ptr<sf::Texture> AssetManager::heartTexture = nullptr;

std::unique_ptr<sf::Font> AssetManager::mainFont = nullptr;

std::unique_ptr<std::vector<sf::IntRect>> AssetManager::heroFrames = nullptr;
std::unique_ptr<std::vector<sf::IntRect>> AssetManager::archerFrames = nullptr;
std::unique_ptr<std::vector<sf::IntRect>> AssetManager::brawlerFrames = nullptr;
std::unique_ptr<std::vector<sf::IntRect>> AssetManager::watcherFrames = nullptr;
std::unique_ptr<std::vector<sf::IntRect>> AssetManager::bossFrames = nullptr;


std::unique_ptr<sf::SoundBuffer> AssetManager::heroJumo = nullptr;
std::unique_ptr<sf::SoundBuffer> AssetManager::heroShoot = nullptr;
std::unique_ptr<sf::SoundBuffer> AssetManager::heroDamage = nullptr;
std::unique_ptr<sf::SoundBuffer> AssetManager::archerDamage = nullptr;
std::unique_ptr<sf::SoundBuffer> AssetManager::brawlerDamage = nullptr;
std::unique_ptr<sf::SoundBuffer> AssetManager::watcherDamage = nullptr;
std::unique_ptr<sf::SoundBuffer> AssetManager::bossDamage = nullptr;
std::unique_ptr<sf::SoundBuffer> AssetManager::enemyShoot = nullptr;
std::unique_ptr<sf::SoundBuffer> AssetManager::powerUp = nullptr;
std::unique_ptr<sf::SoundBuffer> AssetManager::reload = nullptr;

void AssetManager::load() {
    try {
        backgroundTexture = std::make_unique<sf::Texture>();
        heroTexture = std::make_unique<sf::Texture>();
        watcherTexture = std::make_unique<sf::Texture>();
        brawlerTexture = std::make_unique<sf::Texture>();
        coconutTexture = std::make_unique<sf::Texture>();
        platformTexture = std::make_unique<sf::Texture>();
        archerTexture = std::make_unique<sf::Texture>();
        bossTexture = std::make_unique<sf::Texture>();
        candyTexture = std::make_unique<sf::Texture>();
        heartTexture = std::make_unique<sf::Texture>();

        mainFont = std::make_unique<sf::Font>();

        heroFrames = std::make_unique<std::vector<sf::IntRect>>();
        archerFrames = std::make_unique<std::vector<sf::IntRect>>();
        brawlerFrames = std::make_unique<std::vector<sf::IntRect>>();
        watcherFrames = std::make_unique<std::vector<sf::IntRect>>();
        bossFrames = std::make_unique<std::vector<sf::IntRect>>();

        heroJumo = std::make_unique<sf::SoundBuffer>();
        heroShoot = std::make_unique<sf::SoundBuffer>();
        heroDamage = std::make_unique<sf::SoundBuffer>();
        enemyShoot = std::make_unique<sf::SoundBuffer>();
        brawlerDamage = std::make_unique<sf::SoundBuffer>();
        archerDamage = std::make_unique<sf::SoundBuffer>();
        watcherDamage = std::make_unique<sf::SoundBuffer>();
        bossDamage = std::make_unique<sf::SoundBuffer>();
        powerUp = std::make_unique<sf::SoundBuffer>();
        reload = std::make_unique<sf::SoundBuffer>();

        backgroundTexture->loadFromFile("../Assets/Images/Background.png");
        heroTexture->loadFromFile("../Assets/Images/isAnimatedFull.png");
        watcherTexture->loadFromFile("../Assets/Images/dinoWalk.png");
        brawlerTexture->loadFromFile("../Assets/Images/Lantern.png");
        archerTexture->loadFromFile("../Assets/Images/archer.png");
        coconutTexture->loadFromFile("../Assets/Images/coconut.png");
        platformTexture->loadFromFile( "../Assets/Images/platform.png");
        bossTexture->loadFromFile("../Assets/Images/BOSS.png");
        candyTexture->loadFromFile("../Assets/Images/lolly.png");
        heartTexture->loadFromFile("../Assets/Images/heart.png");

        mainFont->loadFromFile("../Assets/Font/mainFont.otf");

        heroJumo->loadFromFile("../Assets/Audio/heroJump.wav");
        heroDamage->loadFromFile("../Assets/Audio/heroDamage.wav");
        heroShoot->loadFromFile("../Assets/Audio/heroShoot.wav");
        enemyShoot->loadFromFile("../Assets/Audio/enemyShoot.wav");
        archerDamage->loadFromFile("../Assets/Audio/archerDamage.wav");
        watcherDamage->loadFromFile("../Assets/Audio/watcherDamage.wav");
        brawlerDamage->loadFromFile("../Assets/Audio/brawlerDamage.wav");
        bossDamage->loadFromFile("../Assets/Audio/bossDamage.wav");
        powerUp->loadFromFile("../Assets/Audio/powerUp.wav");
        reload->loadFromFile("../Assets/Audio/reload.wav");

    } catch (const std::exception& exception) {
        std::cerr << exception.what() << std::endl;
    }

}
void AssetManager::loadTest() {
    try {
        backgroundTexture = std::make_unique<sf::Texture>();
        heroTexture = std::make_unique<sf::Texture>();
        watcherTexture = std::make_unique<sf::Texture>();
        brawlerTexture = std::make_unique<sf::Texture>();
        coconutTexture = std::make_unique<sf::Texture>();
        platformTexture = std::make_unique<sf::Texture>();
        archerTexture = std::make_unique<sf::Texture>();
        bossTexture = std::make_unique<sf::Texture>();
        candyTexture = std::make_unique<sf::Texture>();
        heartTexture = std::make_unique<sf::Texture>();

        mainFont = std::make_unique<sf::Font>();

        heroFrames = std::make_unique<std::vector<sf::IntRect>>();
        archerFrames = std::make_unique<std::vector<sf::IntRect>>();
        brawlerFrames = std::make_unique<std::vector<sf::IntRect>>();
        watcherFrames = std::make_unique<std::vector<sf::IntRect>>();
        bossFrames = std::make_unique<std::vector<sf::IntRect>>();

        heroJumo = std::make_unique<sf::SoundBuffer>();
        heroShoot = std::make_unique<sf::SoundBuffer>();
        heroDamage = std::make_unique<sf::SoundBuffer>();
        enemyShoot = std::make_unique<sf::SoundBuffer>();
        brawlerDamage = std::make_unique<sf::SoundBuffer>();
        archerDamage = std::make_unique<sf::SoundBuffer>();
        watcherDamage = std::make_unique<sf::SoundBuffer>();
        bossDamage = std::make_unique<sf::SoundBuffer>();
        powerUp = std::make_unique<sf::SoundBuffer>();
        reload = std::make_unique<sf::SoundBuffer>();

        backgroundTexture->loadFromFile("../../Assets/Images/Background.png");
        heroTexture->loadFromFile("../../Assets/Images/isAnimatedFull.png");
        watcherTexture->loadFromFile("../../Assets/Images/dinoWalk.png");
        brawlerTexture->loadFromFile("../../Assets/Images/Lantern.png");
        archerTexture->loadFromFile("../../Assets/Images/archer.png");
        coconutTexture->loadFromFile("../../Assets/Images/coconut.png");
        platformTexture->loadFromFile( "../../Assets/Images/platform.png");
        bossTexture->loadFromFile("../../Assets/Images/BOSS.png");
        candyTexture->loadFromFile("../../Assets/Images/lolly.png");
        heartTexture->loadFromFile("../../Assets/Images/heart.png");

        mainFont->loadFromFile("../../Assets/Font/mainFont.otf");

        heroJumo->loadFromFile("../../Assets/Audio/heroJump.wav");
        heroDamage->loadFromFile("../../Assets/Audio/heroDamage.wav");
        heroShoot->loadFromFile("../../Assets/Audio/heroShoot.wav");
        enemyShoot->loadFromFile("../../Assets/Audio/enemyShoot.wav");
        archerDamage->loadFromFile("../../Assets/Audio/archerDamage.wav");
        watcherDamage->loadFromFile("../../Assets/Audio/watcherDamage.wav");
        brawlerDamage->loadFromFile("../../Assets/Audio/brawlerDamage.wav");
        bossDamage->loadFromFile("../../Assets/Audio/bossDamage.wav");
        powerUp->loadFromFile("../../Assets/Audio/powerUp.wav");
        reload->loadFromFile("../../Assets/Audio/reload.wav");

    } catch (const std::exception& exception) {
        std::cerr << exception.what() << std::endl;
    }

}

void AssetManager::setFrames() {
    //HERO
    for(int i = 0; i < 10; i++)
        heroFrames->emplace_back(sf::IntRect(0 + i * 80, 0, 80, 65));
    //ARCHER
    for(int i = 0; i < 16; i++)
        archerFrames->emplace_back(sf::IntRect(0 + i * 80, 0, 80, 83));
    //BRAWLER
    for(int i = 0; i < 20; i++)
        brawlerFrames->emplace_back(sf::IntRect(0 + i * 579, 0, 579, 763));
    //WATCHER
    for(int i = 0; i < 20; i++)
        watcherFrames->emplace_back(sf::IntRect(0 + i * 680, 0, 680, 472));
    //BOSS
    for(int i = 0; i < 14; i++)
        bossFrames->emplace_back(sf::IntRect(0 +  i  * 835, 0,  835, 554));
}

