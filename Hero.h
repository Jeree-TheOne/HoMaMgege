//
// Created by JerEe^ on 01.03.2021.
//

#ifndef UNTITLED3_HERO_H
#define UNTITLED3_HERO_H
#include <windows.h>
#include <string>
#include <iostream>
#include <list>
#include "Perks.h"
using namespace std;
class Hero {
private:
    string Type;
    int Damage;
    int HP;
    int Armor;
    int Intellect;
    int MagicStrength;
    int Gold = 2500;
    Perk Perks[4];
    int Xp;
public:
    void CreateHero(string type)
    {
        ch:
        if (type == "Лучник"){
            Damage = 1;
            HP = 1;
            Armor = 1;
            Intellect = 1;
            MagicStrength = 1;
        }
        else if (type == "Воин"){
            Damage = 1;
            HP = 1;
            Armor = 1;
            Intellect = 1;
            MagicStrength = 1;
        }
        else if (type == "Маг"){
            Damage = 1;
            HP = 1;
            Armor = 1;
            Intellect = 1;
            MagicStrength = 1;
        }
        else{
            cout << "Ты ввел что-то не то, дружочек-пирожочек" << endl;
            Sleep(2000);
            system("cls");
            goto ch;
        }
    }
};
enum {
    Arch,
    Sword,
    Maga
};


#endif //UNTITLED3_HERO_H
