//
// Created by Emanuele Casciaro on 24/11/2019.
//

#include "RecordState.h"

RecordState::RecordState(TargetWindow targetWindow) : GameState(std::move(targetWindow)) {}

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
    targetWindow->clear(sf::Color::Yellow);
}