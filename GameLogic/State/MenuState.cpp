//
// Created by Emanuele Casciaro on 23/11/2019.
//

#include "MenuState.h"

MenuState::MenuState(TargetWindow targetWindow) : GameState(std::move(targetWindow)), menu(Menu(Menu::STYLE::MAIN)) {
    stars = Star::createStars(this->targetWindow);
}

void MenuState::handleSincInput() {
    sf::Event event;
    while(targetWindow->pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            targetWindow->close();
        else if (event.type == sf::Event::Resized) {
            sf::Vector2u size = targetWindow->getSize();
            targetWindow->setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
        }
        else if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
                menu.backward();
            if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
                menu.forward();
            if(event.key.code == sf::Keyboard::Enter) {
                switch (menu.getAction()) {
                    case Menu::MenuItem::TYPE::START:
                        GameEngine::getGameEngine()->getStateHandler().addState(std::make_shared<PlayState>(targetWindow));
                        break;
                    case Menu::MenuItem::TYPE::RECORD:
                        GameEngine::getGameEngine()->getStateHandler().addState(std::make_shared<RecordState>(targetWindow));
                        break;
                    case Menu::MenuItem::TYPE::EXIT:
                        targetWindow->close();
                        break;
                    default:
                        std::cerr << "Caso non valido" << std::endl;
                }
            }
        }
    }
}

void MenuState::computeFrame() {
    float center = GameEngine::getGameEngine()->getWindow()->getView().getCenter().x;
    float offset = GameEngine::getGameEngine()->getWindow()->getView().getSize().x / 2;
    for(auto star : stars) star->updateStar(center - offset - 20, center + offset + 20);
}

void MenuState::drawFrame() {
    targetWindow->clear(sf::Color(19, 24, 98));
    for(auto star : stars) targetWindow->draw(*star);
    menu.draw(targetWindow);

}