//
// Created by Emanuele Casciaro on 24/11/2019.
//

#ifndef ISANGRYREVISED_MENU_H
#define ISANGRYREVISED_MENU_H

#include <iostream>
#include <memory>

#include "SFML/Graphics.hpp"

class MenuItem : public sf::Text {
public:
    enum TYPE {
        START,
        RECORD,
        EXIT,
        RESUME,
        QUIT,
        SCORE,
        INFO,
        NONE
    };
    explicit MenuItem(MenuItem::TYPE type);
    const TYPE& getType() const;

private:
    TYPE type;
};




class Menu {
public:
    enum STYLE {
        CENTERED,
        TOP,
        MAIN
    };
    explicit Menu(STYLE style);
    ~Menu();
    void draw(const std::shared_ptr<sf::RenderWindow>& window);
    void forward();
    void backward();
    const MenuItem::TYPE& getAction() const;
    const STYLE& getStyle() const;
private:
    int active {0};
    int count {0};
    sf::Font font;
    std::vector<std::shared_ptr<MenuItem>> itemList;
    STYLE style;
};


#endif //ISANGRYREVISED_MENU_H
