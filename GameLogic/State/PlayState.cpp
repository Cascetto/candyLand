//
// Created by Emanuele Casciaro on 24/11/2019.
//

#include "PlayState.h"


float PlayState::gravity = 0.04f;

PlayState::PlayState(TargetWindow targetWindow) : GameState(std::move(targetWindow)) {
    background.emplace_back(sf::Sprite(*AssetManager::backgroundTexture));
    background.emplace_back(sf::Sprite(*AssetManager::backgroundTexture));
    float scale = this->targetWindow->getView().getSize().y / background[0].getGlobalBounds().height;
    background[0].scale(scale, scale);
    background[1].scale(scale, scale);
    background[1].setPosition(background[0].getGlobalBounds().width, 0);

    groundLevel = (7.98f / 11.85f) * background[0].getGlobalBounds().height;

    PlayState::gravity = (this->targetWindow->getView().getSize().y) / 4.5f;

    hero = std::make_shared<Hero>(20, 0);
    hero->setPosition(200, 200);
    hero->scale(3, 3);


    platforms.emplace_back(Platform());
    platforms[0].setPosition(2000, 600);

    Timer::resetMainTime();
}

void PlayState::handleSincInput() {
    sf::Event event {};
    while(targetWindow->pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            GameEngine::getGameEngine()->getStateHandler().removeState();
            targetWindow->close();
            break;
        }
        else if (event.type == sf::Event::Resized) {
            sf::Vector2u size = targetWindow->getSize();
            targetWindow->setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
        }
        else if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Escape) {
                //TODO PAUSE MENU
            }
            //TODO RIMUOVI COMANDO 'Z'
            else if(event.key.code == sf::Keyboard::Z) {
                GameEngine::getGameEngine()->getStateHandler().removeState();
            }
            else if(event.key.code == sf::Keyboard::N){
                enemies.emplace_back(GameFactory::makeEnemy(gravity));
            }
        }
    }
}

void PlayState::handleControls() {
    float direction = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        direction = -1;
        hero->revert = 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        direction = 1;
        hero->revert = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if(hero->getPosition().y + hero->getGlobalBounds().height >= groundLevel-1)
            hero->jump();
        else {
            float toe = hero->getPosition().y + hero->getGlobalBounds().height;
            float left = hero->getPosition().x;
            float right= left + hero->getGlobalBounds().width;
            for(const auto &i : platforms){
                if(((i.left <= left && left <= i.right) || (i.left <= right && right <= i.right)) && (i.top <= toe && toe <= i.top + i.height) && (hero->getSpeed().y >= 0)){
                    hero->jump();
                    break;
                }
            }
        }
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        auto bullet = hero->shoot(Timer::getMainTime());
        if(bullet != nullptr)
            bullets.emplace_back(bullet);
    }
    hero->move(sf::Vector2f(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ? 1.3f * direction : direction, 1));
}

void PlayState::computeFrame() {
    moveView();
    handleControls();
    //hero->fixHeight(groundLevel);
}

void PlayState::moveView() {
    sf::View temp = targetWindow->getView();
    temp.move(SLEEP_TIME * GAME_SPEED, 0);
    for (auto& i : background) {
        float pos = i.getPosition().x;
        if (pos + i.getGlobalBounds().width < temp.getCenter().x - temp.getSize().x / 2) {
            i.move(2 * i.getGlobalBounds().width, 0);
        }
    }
    targetWindow->setView(temp);
}

void PlayState::drawFrame() {
    update();
    targetWindow->clear(sf::Color::Black);
    for(const auto& b : background) targetWindow->draw(b);
    targetWindow->draw(*hero);
    for(const auto& e : enemies) targetWindow->draw(*e);
    for(const auto& bullet : bullets) targetWindow->draw(*bullet);
    for(const auto& platform : platforms) targetWindow->draw(platform);


}

void PlayState::update() {
    fixHeight();
    auto heroPos = hero->getPosition();
    for (unsigned long i = 0; i < bullets.size(); i++) {
        bullets[i]->move();
        if (detectCollision(bullets[i]) || isOutside(
                sf::Vector2f(bullets[i]->getPosition().x + bullets[i]->getGlobalBounds().width, bullets[i]->getPosition().y + bullets[i]->getGlobalBounds().height)
                )) {
            bullets.erase(bullets.begin() + i);
        }
    }
    for (auto const& enemy : enemies) {
        enemy->action(heroPos);
        //enemy->fixHeight(groundLevel);
    }
}

bool PlayState::detectCollision(std::shared_ptr<Bullet> &bullet) {
    bool result = false;
    if(bullet->isFriendly()) {
        for (int i = 0; i < enemies.size() && !result; i++) {
            if (bullet->getGlobalBounds().intersects(enemies[i]->getGlobalBounds())) {
                if (enemies[i]->takeDamage()) {
                    enemies.erase(enemies.begin() + i);
                }
                result = true;
            }
        }
    } else {
        if (bullet->getGlobalBounds().intersects(hero->getGlobalBounds())) {
            if(hero->takeDamage())
                result = true;
        }
    }
    return result;
}

bool PlayState::isOutside(sf::Vector2f bottomRight) {
    auto topLeft = targetWindow->getView().getCenter() - (targetWindow->getView().getSize() / 2.f);
    return bottomRight.x < topLeft.x || bottomRight.y < topLeft.y || bottomRight.x > topLeft.x + targetWindow->getView().getSize().x * 2;
}

void PlayState::fixHeight() {
    for (auto i : enemies) {
        float toe = i->getPosition().y + i->getGlobalBounds().height;
        float left = i->getPosition().x;
        float right= left + i->getGlobalBounds().width;
        if(toe > groundLevel){
            i->setPosition(left,groundLevel-(i->getGlobalBounds().height));
            sf::Vector2f newSpeed(i->getSpeed().x, 0);
            i->setSpeed(newSpeed);
        }




    }
    float toe = hero->getPosition().y + hero->getGlobalBounds().height;
    float left = hero->getPosition().x;
    float right= left + hero->getGlobalBounds().width;
    if(toe > groundLevel){
        hero->setPosition(left,groundLevel-(hero->getGlobalBounds().height));
        sf::Vector2f newSpeed(hero->getSpeed().x, 0);
        hero->setSpeed(newSpeed);
    }
    for(const auto &i : platforms){
        if(((i.left <= left && left <= i.right) || (i.left <= right && right <= i.right)) && (i.top <= toe && toe <= i.top + i.height) && (hero->getSpeed().y >= 0)){
            hero->setPosition(sf::Vector2f(left,(i.top - hero->getGlobalBounds().height)));
            sf::Vector2f newSpeed(hero->getSpeed().x, 0);
            hero->setSpeed(newSpeed);
        }
            // TODO nemici






    }
}




