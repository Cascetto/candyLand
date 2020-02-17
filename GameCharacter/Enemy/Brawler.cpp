//
// Created by Emanuele Casciaro on 05/12/2019.
//

#include "Brawler.h"

void Brawler::update() {

}

void Brawler::animate() {

}

Brawler::Brawler(float speed, float g) : GameCharacter(speed, *AssetManager::brawlerTexture, g) {
    setTextureRect(sf::IntRect(0, 0,579 ,763 ));
}

void Brawler::action(sf::Vector2f heroPos) {
    auto direction = heroPos - getPosition();
    direction = direction /= sqrt(direction.x * direction.x + direction.y * direction.y);
    move(sf::Vector2f(direction.x * speed.x, 0));
}