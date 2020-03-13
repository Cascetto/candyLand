//
// Created by Emanuele Casciaro on 24/02/2020.
//

#include "PauseState.h"

PauseState::PauseState(TargetWindow targetWindow, std::vector<sf::Sprite*> prevScreen) : GameState(std::move(targetWindow)), background(prevScreen) {
    pauseMenu = std::make_unique<Menu>(Menu::STYLE::CENTERED);
    backgroundRect.setPosition(this->targetWindow->getView().getCenter() - (this->targetWindow->getView().getSize() / 2.f));
    backgroundRect.setSize(this->targetWindow->getView().getSize());
    backgroundRect.setFillColor(sf::Color(0, 0, 0, 127));
}

void PauseState::drawFrame() {
    targetWindow->clear(sf::Color::Black);
    for(int i = 0; i < background.size(); i++) {
        auto sprite = *(background[i]);
        targetWindow->draw(sprite);
    }
    targetWindow->draw(backgroundRect);
    pauseMenu->draw(targetWindow);

}

void PauseState::computeFrame() {

}

void PauseState::handleSyncInput() {
    sf::Event event;

    while(targetWindow->pollEvent(event)) {
        sf::View newView;
        PlayState* temp = nullptr;
        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Escape) {
                GameEngine::getGameEngine()->getStateHandler().removeState();
            } else if((event.key.code == sf::Keyboard::S) || (event.key.code == sf::Keyboard::Down)) {
                pauseMenu->forward();
            } else if((event.key.code == sf::Keyboard::W) || (event.key.code == sf::Keyboard::Up)) {
                pauseMenu->backward();
            } else if(event.key.code == sf::Keyboard::Enter) {
                switch(pauseMenu->getAction()) {
                    case Menu::MenuItem::RESUME:
                        GameEngine::getGameEngine()->getStateHandler().removeState();
                        break;
                    case Menu::MenuItem::QUIT:
                        GameEngine::getGameEngine()->getStateHandler().removeState();
                        temp = dynamic_cast<PlayState*>(&(*GameEngine::getGameEngine()->getStateHandler().getState()));
                        temp->clear();
                        GameEngine::getGameEngine()->getStateHandler().removeState();
                        GameEngine::getGameEngine()->playMain();
                        newView = targetWindow->getView();
                        newView.setCenter(newView.getSize() / 2.f);
                        targetWindow->setView(newView);
                        break;
                    default:
                        std::cerr << "Caso non trovato";
                }
            }
        }
    }
}