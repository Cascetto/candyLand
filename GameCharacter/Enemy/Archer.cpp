//
// Created by Emanuele Casciaro on 30/12/2019.
//

#include "Archer.h"


Archer::Archer(float gravity) : GameCharacter(0, AssetManager::textures.at("ARCHER"), gravity){
    for (int i = 0; i < 20; i++) {
        frame.emplace_back(sf::IntRect(240 * i ,0,240,439));
    }
    setTextureRect(sf::IntRect(0, 0, 80, 94));
    lastTime = Timer::getTimer().getMainTime() + static_cast<float>(rand() % 1001 - 500) / 10000;
    rof = static_cast<float>(rand() % 9 + 6) /  3.f;
    GameCharacter::lives = 3;
    animatorManager.setFrames(AssetManager::frames.at("ARCHER_FRAMES"));
    animatorManager.setFrameTime(1);

    hitSound.setBuffer(AssetManager::sounds.at("ARCHER_DAMAGE"));
}


Bullet* Archer::action(sf::Vector2f heroPos) {
    sf::Vector2f direction = heroPos - getPosition();
    if(direction.x < 0) {
        revert = 0;
        animatorManager.action = Animator::IDLE_BACK;
    }
    else {
        revert = 1;
        animatorManager.action = Animator::IDLE_FRONT;
    }
    Bullet* bullet = nullptr;
    float time = Timer::getTimer().getMainTime();
    if(time - lastTime >= rof) {
        direction /= sqrtf(powf(direction.x, 2) + powf(direction.y, 2));
        bullet = new Bullet(direction, 30);
        bullet->setPosition(getPosition());
        bullet->scale(0.3f, 0.3f),
        lastTime = time;
        shootSound.play();
    }
    return bullet;
}
