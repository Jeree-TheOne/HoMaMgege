//
// Created by JerEe^ on 01.03.2021.
//

#ifndef UNTITLED3_PERKS_H
#define UNTITLED3_PERKS_H
#include <iostream>
#include "Randomize.h"
#include "Format.h"
using namespace std;

class Perks {
private:
    string Name;
    string Action;
    int Stage;
    string perks [10][3] = {
            {"Стрельба","D5","1"},
            {"Ученый","E2","1"},
            {"Уклонение","A5","1"},
            {"Нападение","D5","1"},
            {"Доспехи","A5","1"},
            {"Мистицизм","MS5","1"},
            {"Атака","D5","1"},
            {"Разум","I5","1"},
            {"Волшебство","MS5","1"},
            {"Золотое косание","G50","1"}
    };

public:
    Perks(){
        Name = "";
        Action = "";
        Stage = 0;
    }
    void NewPerk(){
        int index = Randomize::GetRand(0,9);
        Name = perks[index][0];
        Action = perks[index][1];
        Stage = 1;
    }

    void UpgradePerk(){
        Action = Format::UpPerk(Action, Stage);
        ++Stage;
    }
    string GetName(){
        return Name;
    }
    string GetAction(){
        return Action;
    }
    int GetStage(){
        return Stage;
    }
};


#endif //UNTITLED3_PERKS_H
