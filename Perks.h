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
    string Action;
    int Stage;
    string perks [10][3] = {
            {"Стрельба","RD10","1"},
            {"Удача","C10","1"},
            {"Уклонение","E10","1"},
            {"Нападение","AD10","1"},
            {"Доспехи","A10","1"},
            {"Мистицизм","M10","1"},
            {"Атака","AD10","1"},
            {"Разум","I25","1"},
            {"Волшебство","MD10","1"},
            {"Сопротивление магии","MR10","1"}
    };

public:
    string Name;
    Perks(){
        int index = Randomize::GetRand(0,9);
        Name = perks[index][0];
        Action = perks[index][1];
        Stage = 1;
    }
    void UpgradePerk(){
        if (Stage == 3)
        {
            cout << "Навык уже максимального уровня";
            return;
        }
        Format::UpPerk(Action, Stage);
        ++Stage;
    }
};


#endif //UNTITLED3_PERKS_H
