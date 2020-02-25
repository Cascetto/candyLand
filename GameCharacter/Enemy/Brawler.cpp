//
// Created by Emanuele Casciaro on 05/12/2019.
//

#include "Brawler.h"

void Brawler::animate() {
    setTextureRect(frame[((frameCounter++) % 10) + revert * 10]);
    if(frameCounter >= 100) frameCounter = 0;

}

Brawler::Brawler(float speed, float g) : GameCharacter(speed, *AssetManager::brawlerTexture, g) {
    setTextureRect(sf::IntRect(0, 0,579 ,763));
    for (int i = 0; i < 20; i++) {
        frame.emplace_back(sf::IntRect(579 * i ,0,579,763));
    }


}

Bullet* Brawler::action(sf::Vector2f heroPos) {
    auto direction = heroPos - getPosition();
    if(direction.x < 0)
        revert = 0;
    else revert = 1;
    direction = direction /= sqrt(direction.x * direction.x + direction.y * direction.y);
    move(sf::Vector2f(direction.x * speed.x, 0));
    return nullptr;
}