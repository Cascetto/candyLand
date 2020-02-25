//
// Created by Emanuele Casciaro on 24/11/2019.
//

#include "RecordState.h"
//10x + 11x/3 = h
//41x = 3h
//x = 3h/41

RecordState::RecordState(TargetWindow targetWindow) : GameState(std::move(targetWindow)) {

    entries = RecordInsState::parser();
    float height = this->targetWindow->getView().getSize().y * 3 / 41.f;
    float center = this->targetWindow->getView().getCenter().x;
    float y = height/3;
    sf::Text temp;
    for(int i = 0; i < entries.size(); i++) {
        char tempStr[11];
        temp = sf::Text(entries[i].name, *AssetManager::mainFont, height);
        temp.setOutlineThickness(6);
        temp.setOutlineColor(sf::Color::Black);
        temp.setPosition(center - temp.getGlobalBounds().width - 100, y);
        record.emplace_back(temp);
        sprintf(tempStr, "%ld", entries[i].score);
        temp.setString(std::string(tempStr));
        temp.setPosition(center + 100, y);
        record.emplace_back(temp);
        y += height + height/3;
    }

}

void RecordState::handleSincInput() {
    sf::Event event;
    while(targetWindow->pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            targetWindow->close();
        else if (event.type == sf::Event::Resized) {
            sf::Vector2u size = targetWindow->getSize();
            targetWindow->setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
        }
        else if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Escape)
                GameEngine::getGameEngine()->getStateHandler().removeState();
        }
    }
}

void RecordState::computeFrame() {

}

void RecordState::drawFrame() {
    targetWindow->clear(sf::Color::Red);
    for(const auto& r : record) targetWindow->draw(r);
}