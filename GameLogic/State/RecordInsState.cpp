//

#include "RecordInsState.h"
#include "../AssetManager.h"
#include "../GameEngine.h"

//
// Created by Emanuele Casciaro on 24/02/2020.

std::vector<Record> RecordInsState::recordList = std::vector<Record>();

RecordInsState::RecordInsState(TargetWindow targetWindow, long int score) : GameState(std::move(targetWindow)), score(score) {
    recordName = sf::Text(std::string(str),*AssetManager::mainFont,200);
    sf::Vector2f size(recordName.getGlobalBounds().width, recordName.getGlobalBounds().height);
    recordName.setPosition(this->targetWindow->getView().getCenter() - size / 2.f);
    recordList = parser();
    char scoreStr[10];
    sprintf(scoreStr, "%ld", score);
    std::string punteggio(scoreStr);
    scoreLabel = sf::Text(std::string(punteggio), *AssetManager::mainFont, 300);
    sf::Vector2f size2(scoreLabel.getGlobalBounds().width,100);
    scoreLabel.setPosition(this->targetWindow->getView().getCenter().x - size2.x / 2.f, size2.y);

    for(const auto& r : recordList){
        if(score > r.score)
            newRecord = true;
        else
            newRecordPos++;
    }
}

void RecordInsState::computeFrame() {
    if(!newRecord) {
        GameEngine::getGameEngine()->getStateHandler().removeState();
        GameEngine::getGameEngine()->getStateHandler().removeState();

        sf::View view = targetWindow->getView();
        view.setCenter(view.getSize()/2.f);
        targetWindow->setView(view);
    }
}

void RecordInsState::handleSyncInput() {
    sf::Event event;
    while (targetWindow->pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            targetWindow->close();
        else if (event.type == sf::Event::Resized) {
            sf::Vector2u size = targetWindow->getSize();
            targetWindow->setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
        } else if (event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Enter && index==3){
                GameEngine::getGameEngine()->getStateHandler().removeState();
                GameEngine::getGameEngine()->getStateHandler().removeState();

                sf::View view = targetWindow->getView();
                view.setCenter(view.getSize()/2.f);
                targetWindow->setView(view);

                saveRecord();

            } else {
                char temp = KeytoChar(event.key.code);
                if(temp == -1 && index > 0) {
                        str[--index] = '_';
                }
                else if(temp != 0 && temp != -1 && index < 3)
                    str[index++] = temp;
                recordName.setString(std::string(str));
            }
        }

    }
}

void RecordInsState::saveRecord() {

    recordList = parser();

    for(int i = recordList.size() - 1; i > newRecordPos; i--) {
        recordList[i] = recordList[i - 1];
    }
    recordList[newRecordPos].name = std::string(str);
    recordList[newRecordPos].score = score;

    std::ofstream record("../Assets/record.txt", std::ios::out | std::ios::trunc);
    std::string buffer;
    char temp[11];
    if(record.is_open()){
        for(const auto& r : recordList) {
            sprintf(temp, "%ld", r.score);
            buffer.append("{" + r.name +  ":" + std::string(temp) + "}");
        }
        record << buffer;
        record.close();
    }
}

void RecordInsState::drawFrame() {
    targetWindow->clear();
    targetWindow->draw(scoreLabel);
    targetWindow->draw(recordName);
}

char RecordInsState::KeytoChar(sf::Keyboard::Key keyCode) {
    char result = 0;
    switch(keyCode) {
        case sf::Keyboard::A:
            result = 'A';
            break;
        case sf::Keyboard::B:
            result = 'B';
            break;
        case sf::Keyboard::C:
            result = 'C';
            break;
        case sf::Keyboard::D:
            result = 'D';
            break;
        case sf::Keyboard::E:
            result = 'E';
            break;
        case sf::Keyboard::F:
            result = 'F';
            break;
        case sf::Keyboard::G:
            result = 'G';
            break;
        case sf::Keyboard::H:
            result = 'H';
            break;
        case sf::Keyboard::I:
            result = 'I';
            break;
        case sf::Keyboard::L:
            result = 'L';
            break;
        case sf::Keyboard::M:
            result = 'M';
            break;
        case sf::Keyboard::N:
            result = 'N';
            break;
        case sf::Keyboard::O:
            result = 'O';
            break;
        case sf::Keyboard::P:
            result = 'P';
            break;
        case sf::Keyboard::Q:
            result = 'Q';
            break;
        case sf::Keyboard::R:
            result = 'R';
            break;
        case sf::Keyboard::S:
            result = 'S';
            break;
        case sf::Keyboard::U:
            result = 'U';
            break;
        case sf::Keyboard::V:
            result = 'V';
            break;
        case sf::Keyboard::Z:
            result = 'Z';
            break;
        case sf::Keyboard::J:
            result = 'J';
            break;
        case sf::Keyboard::K:
            result = 'K';
            break;
        case sf::Keyboard::Y:
            result = 'Y';
            break;
        case sf::Keyboard::W:
            result = 'W';
            break;
        case sf::Keyboard::X:
            result = 'X';
            break;
        case sf::Keyboard::BackSpace:
            result = -1;
            break;
        default:
            std::clog << "Tasto non supportato";
    }
    return result;
}

std::vector<Record> RecordInsState::parser() {
    std::vector<Record> list;

    std::string buffer, str;
    std::ifstream record("../Assets/record.txt");

    if(record.is_open()){
        while(!record.eof()) {
            std::getline(record, str);
            buffer.append(str);
        }
        record.close();

        size_t pos;
        size_t column;
        size_t close;
        size_t notFound = std::string::npos;

        while(true) {
            pos = buffer.find('{');
            if(pos == notFound) break;
            else {
                column = buffer.find(':');
                close = buffer.find('}');
                Record temp;
                temp.name = buffer.substr(pos + 1, column - 1);
                temp.score = stoi(buffer.substr(column +  1, close - 1));
                list.emplace_back(temp);
                buffer = buffer.substr(close + 1);
            }
        }

    }
    return list;
}
