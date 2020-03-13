//
// Created by Emanuele Casciaro on 24/02/2020.
//

#ifndef ISANGRYREVISED_RECORDINSSTATE_H
#define ISANGRYREVISED_RECORDINSSTATE_H


#include "GameState.h"
#include <fstream>

struct Record {
    long int score;
    std::string name;
};

class RecordInsState : public GameState {
public:
    RecordInsState(TargetWindow targetWindow, long int score);
    void computeFrame() override ;
    void handleSyncInput() override;
    void drawFrame() override;
    static std::vector<Record> parser();
private:
    char str[4] = {'_', '_', '_', '\0'};
    int index{0};
    int newRecordPos {0};
    long int score {0};
    constexpr const static char* const fileName = {"../Assets/record.txt"};
    bool newRecord {false};

    void saveRecord();


    sf::Text recordName;
    sf::Text scoreLabel;

    static std::vector<Record> recordList;
    char KeytoChar(sf::Keyboard::Key keyCode);
};


#endif //ISANGRYREVISED_RECORDINSSTATE_H
