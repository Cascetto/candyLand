//
// Created by Emanuele Casciaro on 24/11/2019.
//

#include "Menu.h"

Menu::MenuItem::MenuItem(Menu::MenuItem::TYPE type) : type(type){
    std::string btnText;
    switch (type) {
        case MenuItem::TYPE::START:
            btnText = "Gioca";
            break;
        case MenuItem::TYPE::RECORD:
            btnText = "Record";
            break;
        case MenuItem::TYPE::EXIT:
            btnText = "Chiudi gioco";
            break;
        case MenuItem::TYPE::QUIT:
            btnText = "Menu principale";
            break;
        case MenuItem::TYPE::RESUME:
            btnText = "Riprendi";
            break;
        default:
            std::cerr << "Oggetto sbagliato";
    }
    setString(btnText);
}

const Menu::MenuItem::TYPE& Menu::MenuItem::getType() const {
    return type;
}

Menu::Menu(Menu::STYLE style) : style(style){
    if(!font.loadFromFile("./Assets/Font/mainFont.otf"))
        std::cerr << "Font non trovato" << std::endl;
    if(style == Menu::STYLE::MAIN) {
        itemList.emplace_back(std::make_shared<MenuItem>(MenuItem::TYPE::START));
        itemList.emplace_back(std::make_shared<MenuItem>(MenuItem::TYPE::RECORD));
        itemList[1]->setFont(font);
        itemList.emplace_back(std::make_shared<MenuItem>(MenuItem::TYPE::EXIT));
        itemList[2]->setFont(font);
        itemList[active]->setFont(font);
        itemList[active]->setFillColor(sf::Color::Red);
        count = itemList.size();
    } else if (style == Menu::STYLE::TOP) {
        itemList.emplace_back(std::make_shared<MenuItem>(MenuItem::TYPE::SCORE));
        itemList.emplace_back(std::make_shared<MenuItem>(MenuItem::TYPE::INFO));
        count = itemList.size();
    } else if (style == Menu::STYLE::CENTERED) {
        itemList.emplace_back(std::make_shared<MenuItem>(MenuItem::TYPE::RESUME));
        itemList.emplace_back(std::make_shared<MenuItem>(MenuItem::TYPE::QUIT));
        itemList[active]->setFillColor(sf::Color::Red);
        count = itemList.size();
    } else std::cerr << "Menu non definto";

}

Menu::~Menu() {
    itemList.clear();
}

void Menu::draw(const std::shared_ptr<sf::RenderWindow>& window) {
    sf::View actualView = window->getView();
    sf::Vector2f origin, dim, pos;
    dim = actualView.getSize();
    origin = actualView.getCenter();
    origin.x -= dim.x / 2;
    origin.y -= dim.y / 2;

    if (style == STYLE::MAIN) {
        int height = count * (64 + 8);
        pos = actualView.getCenter();
        pos.y -= height / 2;
        for (auto i : itemList) {
            i->setCharacterSize(64);
            sf::FloatRect s = i->getGlobalBounds();
            i->setPosition(pos.x, pos.y);
            i->setOrigin(s.width / 2 , s.height / 2);
            pos.y += 72;
            window->draw(*i);
        }
    } else if (style == STYLE::TOP) {
        pos.y = origin.y + 10;
        pos.x = origin.x + 10;
        for (auto i : itemList) {
            i->setPosition(pos);
            i->setFont(font);
            i->setCharacterSize(64);
            float size = i->getGlobalBounds().width;
            pos.x += size + 60;
            window->draw(*i);
        }
    } else if (style == STYLE::CENTERED) {
        int height = count * (64 + 8);
        pos = actualView.getCenter();
        pos.y -= height / 2;
        for (auto i : itemList) {
            i->setCharacterSize(64);
            i->setFont(font);
            sf::FloatRect s = i->getGlobalBounds();
            i->setPosition(pos.x, pos.y);
            i->setOrigin(s.width / 2 , s.height / 2);
            pos.y += 72;
            window->draw(*i);
        }
        //...
    }
}

void Menu::forward() {
    itemList[active]->setFillColor(sf::Color::White);
    if (active >= count - 1)
        active = 0;
    else active++;
    itemList[active]->setFillColor(sf::Color::Red);
}
void Menu::backward() {
    itemList[active]->setFillColor(sf::Color::White);
    if (active == 0)
        active = count - 1;
    else active--;
    itemList[active]->setFillColor(sf::Color::Red);
}

const Menu::MenuItem::TYPE& Menu::getAction() const {
    return itemList[active]->getType();
}
