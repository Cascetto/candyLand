//
// Created by Emanuele Casciaro on 24/11/2019.
//

#include "PlayState.h"


float PlayState::gravity = 0.04f;

PlayState::PlayState(TargetWindow targetWindow) : GameState(std::move(targetWindow)) {
    background.emplace_back(new sf::Sprite(*AssetManager::backgroundTexture));
    background.emplace_back(new sf::Sprite(*AssetManager::backgroundTexture));
    float scale = this->targetWindow->getView().getSize().y / background[0]->getGlobalBounds().height;
    background[0]->scale(scale, scale);
    background[1]->scale(scale, scale);
    background[1]->setPosition(background[0]->getGlobalBounds().width, 0);
    groundLevel = (7.98f / 11.85f) * background[0]->getGlobalBounds().height;
    generate(background[0]->getPosition().x, background[0]->getPosition().x + background[0]->getGlobalBounds().width);
    generate(background[1]->getPosition().x, background[1]->getPosition().x + background[1]->getGlobalBounds().width);
/*
    sf::View newView = this->targetWindow->getView();
    newView.setCenter(newView.getSize() / 2.f);
    this->targetWindow->setView(newView);
*/
    PlayState::gravity = (this->targetWindow->getView().getSize().y) / 4.5f;

    hero = std::make_shared<Hero>(20, 0);
    hero->setPosition(200, 200);
    hero->scale(3, 3);
    for(int i = 0; i <  5; i++){
        sf::Sprite* heart = new sf::Sprite;
        heart->setTexture(*AssetManager::heartTexture);
        heart->scale(0.1f, 0.1f);
        heart->setPosition(20 + heart->getGlobalBounds().width * i, 20);
        lives.emplace_back(heart);
    }
    for(int i = 0; i < hero->maxAmmo; i++){
        sf::Sprite* coconut = new sf::Sprite;
        coconut->setTexture(*AssetManager::coconutTexture);
        coconut->scale(0.4f, 0.4f);
        coconut->setPosition(20 + coconut->getGlobalBounds().width * i, 200);
        ammo.emplace_back(coconut);
    }
    scoreLabel = sf::Text("0", *AssetManager::mainFont, 216);
    sf::Vector2f textPos = this->targetWindow->getView().getSize();
    textPos.x = textPos.x - 60 - scoreLabel.getGlobalBounds().width;
    textPos.y = 30;
    scoreLabel.setPosition(textPos);
    scoreLabel.setOutlineColor(sf::Color::Black);
    scoreLabel.setOutlineThickness(5);
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
            //TODO RIMUOVI COMANDO 'Z'
            if(event.key.code == sf::Keyboard::Z) {
                GameEngine::getGameEngine()->getStateHandler().removeState();
            }
            else if(event.key.code == sf::Keyboard::N){
                enemies.emplace_back(GameFactory::makeEnemy(gravity));
            } else if(event.key.code == sf::Keyboard::Escape) {
                std::vector<sf::Sprite*> objects;
                for(auto b : background) objects.emplace_back(b);
                for(auto p : platforms) objects.emplace_back(p);
                for(auto c : candies) objects.emplace_back(c);
                for(auto e : enemies) objects.emplace_back(e);
                for(auto b : bullets) objects.emplace_back(b);
                objects.emplace_back(&(*hero));
                for(auto l : lives) objects.emplace_back(l);
                for(int i = 0; i < hero->currwntAmmo; i++) objects.emplace_back(ammo[i]);


                std::shared_ptr<GameState> pause = std::make_shared<PauseState>(targetWindow, objects);
                GameEngine::getGameEngine()->getStateHandler().addState(pause);
            }
        }
    }
}

void PlayState::handleControls() {
    float direction = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        direction = -1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        direction = 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(hero->getPosition().y + hero->getGlobalBounds().height >= groundLevel-1)
            hero->jump();
        else {
            float toe = hero->getPosition().y + hero->getGlobalBounds().height;
            float left = hero->getPosition().x;
            float right= left + hero->getGlobalBounds().width;
            for(const auto &i : platforms){
                if(((i->left <= left && left <= i->right) || (i->left <= right && right <= i->right)) &&
                (i->top <= toe && toe <= i->top + i->height) && (hero->getSpeed().y >= 0)){
                    hero->jump();
                    break;
                }
            }
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        hero->currwntAmmo = hero->maxAmmo;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
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
    float distance = SLEEP_TIME * GAME_SPEED;
    sf::View temp = targetWindow->getView();
    temp.move(distance, 0);
    for (auto& i : background) {
        float pos = i->getPosition().x;
        if (pos + i->getGlobalBounds().width < temp.getCenter().x - temp.getSize().x / 2) {
            i->move(2 * i->getGlobalBounds().width, 0);
            generate(i->getPosition().x, i->getPosition().x + i->getGlobalBounds().width);
        }
    }
    for(auto& heart : lives) heart->move(distance, 0);
    for(auto& a : ammo) a->move(distance, 0);
    targetWindow->setView(temp);
    scoreLabel.move(distance, 0);
}

void PlayState::drawFrame() {
    updateGame();
    targetWindow->clear(sf::Color::Black);
    for(const auto& b : background) targetWindow->draw(*b);
    for(const auto& platform : platforms) targetWindow->draw(*platform);
    for(const auto& bullet : bullets) targetWindow->draw(*bullet);
    for(const auto& e : enemies) targetWindow->draw(*e);
    for(const auto& c : candies) targetWindow->draw(*c);
    targetWindow->draw(*hero);
    for(const auto& heart : lives) targetWindow->draw(*heart);
    for(int i = 0; i < hero->currwntAmmo; i++) targetWindow->draw(*ammo[i]);


    targetWindow->draw(scoreLabel);


}

void PlayState::updateGame() {
    fixHeight();
    auto heroPos = hero->getPosition();
    for (unsigned long i = 0; i < bullets.size(); i++) {
        bullets[i]->move();
        if (detectCollision(bullets[i]) ||
        isOutsideLeft(bullets[i]->getPosition().x) ||
        isOutsideRight(bullets[i]->getPosition().x + (bullets[i]->getGlobalBounds().width / 2))) {
            bullets.erase(bullets.begin() + i);
        }
    }
    for (auto const& enemy : enemies) {
        if(!isOutsideRight(enemy->getPosition().x)){
            auto bullet = enemy->action(heroPos);
            if(bullet != nullptr) bullets.emplace_back(bullet);
                enemy->animate();
        }
        //enemy->fixHeight(groundLevel);
    }
    auto heroRect = hero->getGlobalBounds();
    for (int i = 0; i < candies.size(); i++) {
        if(candies[i]->getGlobalBounds().intersects(heroRect)) {
            candies.erase(candies.begin() + i);
            hero->powerUp();
        }
    }
    for (int i = 0; i < enemies.size(); i++) {
        if(enemies[i]->getGlobalBounds().intersects(heroRect))
            if(!lives.empty()){
                enemies.erase(enemies.begin() + i);
                lives.pop_back();
            }
    }
    if(lives.empty() || isOutsideLeft(heroRect.left + heroRect.width)){
        std::shared_ptr<GameState> insRecordState = std::make_shared<RecordInsState>(targetWindow, score);
        GameEngine::getGameEngine()->getStateHandler().addState(insRecordState);
    }
}

bool PlayState::detectCollision(Bullet* bullet) {
    bool result = false;
    auto heroRect = hero->getGlobalBounds();
    if(bullet->isFriendly()) {
        for (int i = 0; i < enemies.size() && !result; i++) {
            if (bullet->getGlobalBounds().intersects(enemies[i]->getGlobalBounds())) {
                if (enemies[i]->takeDamage()) {
                    enemies[i]->notifyObservers();
                    enemies.erase(enemies.begin() + i);
                }
                result = true;
            }
        }
    } else {
        if (bullet->getGlobalBounds().intersects(heroRect)) {
            if(!lives.empty()){
                lives.pop_back();
                result = true;
            }
        }
    }
    return result;
}

bool PlayState::isOutsideLeft(float rightBorder) {
    float viewLeftBorder = targetWindow->getView().getCenter().x - (targetWindow->getView().getSize().x / 2.f);
    return rightBorder < viewLeftBorder;
}

bool PlayState::isOutsideRight(float leftBorder) {
    float viewRightBorder = targetWindow->getView().getCenter().x + (targetWindow->getView().getSize().x / 2.f);
    return leftBorder > viewRightBorder;
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
        if(((i->left <= left && left <= i->right) || (i->left <= right && right <= i->right)) &&
        (i->top <= toe && toe <= i->top + i->height) && (hero->getSpeed().y >= 0)){
            hero->setPosition(sf::Vector2f(left,(i->top - hero->getGlobalBounds().height)));
            sf::Vector2f newSpeed(hero->getSpeed().x, 0);
            hero->setSpeed(newSpeed);
        }
            // TODO nemici






    }
}

void PlayState::generate(float startPoint, float endPoint) {
    //caso 1: brawler (spazio 500 - 50 * (level - 1)) % 20
    //caso 2: platform (spazio 624 - 50 * (level-1)) % 20
    //caso 3: platform + archer (spazio 624 - 50 * (level-1)) % 20
    //caso 4: stalker (spazio 500 - 40 * (level - 1)) % 20
    //caso 5: boss (spazio 1000 - 100 * (level - 1)) % 5
    //caso 6: caramella (spazio 50) % 15
    int prevCase = -1;
    startPoint += 1000;
    endPoint += 1000;
    while (startPoint < endPoint) {
        int generateCase = (rand() % 100) + 1;
        int offset = (rand() % 201) + 600;
        GameCharacter *enemy = nullptr;
        if ((generateCase <= 20) && prevCase != 1) {
            enemy = GameFactory::makeBrawlewr(gravity);
            enemy->setPosition(startPoint, groundLevel - enemy->getGlobalBounds().height);
            startPoint += 500 - 50 * (level - 1);
            prevCase = 1;
        } else if ((generateCase > 20 && generateCase <= 40) && prevCase != 2  && prevCase != 3) {
            auto platform = GameFactory::makePlatform();
            platform->setPosition(startPoint, offset);
            platforms.emplace_back(platform);
            startPoint += 500 - 50 * (level - 1);
            prevCase = 2;
        } else if ((generateCase > 40 && generateCase <= 60) && prevCase != 2 && prevCase != 3) {
            auto platform = GameFactory::makePlatform();
            platform->setPosition(startPoint, offset);
            platforms.emplace_back(platform);
            enemy = GameFactory::makeArcher(gravity);
            enemy->setPosition(startPoint, offset - enemy->getGlobalBounds().height);
            startPoint += 500 - 50 * (level - 1);
            prevCase = 3;
        } else if ((generateCase > 60 && generateCase <= 80) && prevCase != 4) {
            enemy = GameFactory::makeWatcher(gravity);
            enemy->setPosition(startPoint, groundLevel - enemy->getGlobalBounds().height);
            startPoint += 500 - 40 * level;
            prevCase = 4;
        } else if (generateCase > 80 && generateCase <= 85 && !checkBoss()) {
            enemy = GameFactory::makeBoss(gravity);
            enemy->setPosition(startPoint, groundLevel - enemy->getGlobalBounds().height);
            startPoint += 1000 - 100 * (level - 1);
            prevCase = 5;
        } else if(generateCase > 85 && generateCase <= 100 && prevCase != 6) {
            auto candy = GameFactory::makeCandy();
            candy->setPosition(startPoint, groundLevel - candy->getGlobalBounds().height);
            candies.emplace_back(candy);
            prevCase = 6;
        }
        if (enemy != nullptr) {
            enemies.emplace_back(enemy);
            enemy->registerObserver(this);
        }
    }
}

bool PlayState::checkBoss() {
    Boss* ptr;
    for(auto i: enemies){
        ptr = dynamic_cast<Boss*>(i);
        if(ptr != nullptr)
            return true;
    }
    return false;
}

void PlayState::update() {
    score += 50;
    char scoreStr[10];
    sprintf(scoreStr, "%ld", score);
    std::string str(scoreStr);
    float oldWidth = scoreLabel.getGlobalBounds().width;
    scoreLabel.setString(str);
    if(scoreLabel.getGlobalBounds().width > oldWidth)
        scoreLabel.move(oldWidth - scoreLabel.getGlobalBounds().width, 0);
    if(score <= 1000) level = 1;
    else if(score > 1000 && score <= 2000) level = 2;
    else if(score > 2000 && score <= 3000) level = 3;
    else if(score > 3000 && score <= 4000) level = 4;
    else if(score > 5000 && score <= 6000) level = 5;
    else level = 6;
}


