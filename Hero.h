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
#include "Equipment.h"
#include "Spells.h"
#include "Randomize.h"
using namespace std;

enum Types{
    Archer = 1,
    Warrior,
    Mag
};

class Hero {
private:
    string Type;
    int Damage;
    int HP;
    int Armor;
    int Intellect;
    int MagicStrength;
    int Gold = 2500;
    Perks perks[4];
    //Equipment equipment[1];
    int Xp = 0;
public:
    void CreateHero(Types type)
    {
        switch (type) {
            case 1: //По номеру типа
                Type = "Лучник";
                Damage = 1;//+ ((new Randomize)->getRandomNumber(1,1));|| Используем ранд чтоб сделать разброс статов.
                HP = 1;
                Armor = 1;
                Intellect = 1;
                MagicStrength = 1;/* Хуй знает как забить класс хуй пойми откуда в массив классов хуй пойми откуда
                static Perks* d = new Perks(); ебал плюсы
                d->AddPerk("");-----------МБ МОЖНО ЗАБИТЬ МАССИВ ИЗ ДРУГОГО МЕТОДА--------------------
                perks[0] = d;*/
                break;
            case 2: //По номеру типа
                Type = "Лучник";
                Damage = 1;//+ ((new Randomize)->getRandomNumber(1,1));|| Используем ранд чтоб сделать разброс статов.
                HP = 1;
                Armor = 1;
                Intellect = 1;
                MagicStrength = 1;/* Хуй знает как забить класс хуй пойми откуда в массив классов хуй пойми откуда
                static Perks* d = new Perks(); ебал плюсы
                d->AddPerk("");
                perks[0] = d;*/
                break;
            case 3: //По номеру типа
                Type = "Лучник";
                Damage = 1;//+ ((new Randomize)->getRandomNumber(1,1));|| Используем ранд чтоб сделать разброс статов.
                HP = 1;
                Armor = 1;
                Intellect = 1;
                MagicStrength = 1;/* Хуй знает как забить класс хуй пойми откуда в массив классов хуй пойми откуда
                static Perks* d = new Perks(); ебал плюсы
                d->AddPerk("");
                perks[0] = d;*/
                break; //Ну тип герой создается, но ++ сосет, надо задать каждому индивидуальные
                        //значения и разброс
        }
    }
};


#endif //UNTITLED3_HERO_H
