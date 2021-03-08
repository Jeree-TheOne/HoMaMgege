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
    int Xp = 0;
    int Lvl = 1;
public: //todo: Изменить массивы на векторы
    string EquipInventory[10]; // Слоты инвенторя Helmet, Amulet, ChestArmor, LeftHand, RightHand, Ring, Nogi, Pet, Access
    vector<Perks> perks; //Перки изначально дается 2 рандомных, не повторяются
    //string SpellBook[10]; Книжка спеллов, хз какой у нее размер, мб можно листом сделать
    list<string> Inventory;
    Hero(int type)
    {
        switch (type) {
            case 1: //По номеру типа
                Type = "Лучник";
                Damage = 7 + Randomize::GetRand(0,3);
                HP = 5 + Randomize::GetRand(0,2);
                Armor = 1 + Randomize::GetRand(0,2);
                Intellect = 1 + Randomize::GetRand(0,1);
                MagicStrength = 1 + Randomize::GetRand(0,1);
                perks.push_back(Perks());
                st:
                perks.push_back(Perks());
                if (perks[0].Name == perks[1].Name) {
                    perks.pop_back();
                    goto st;
                }
                break;
            case 2: //По номеру типа
                Type = "Воин";
                Damage = 5 + Randomize::GetRand(0,3);
                HP = 6 + Randomize::GetRand(0,4);
                Armor = 4 + Randomize::GetRand(0,3);
                Intellect = 1 + Randomize::GetRand(0,1);
                MagicStrength = 1 + Randomize::GetRand(0,1);
                perks.push_back(Perks());
            st1:
                perks.push_back(Perks());
                if (perks[0].Name == perks[1].Name) {
                    perks.pop_back();
                    goto st1;
                }
                break;
            case 3: //По номеру типа
                Type = "Волшебник";
                Damage = 3 + Randomize::GetRand(0,2);
                HP = 2 + Randomize::GetRand(0,2);
                Armor = 0 + Randomize::GetRand(0,1);
                Intellect = 5 + Randomize::GetRand(0,3);
                MagicStrength = 5 + Randomize::GetRand(0,3);
                perks.push_back(Perks());
            st2:
                perks.push_back(Perks());
                if (perks[0].Name == perks[1].Name) {
                    perks.pop_back();
                    goto st2;
                }
                break;
        }
    }
    void GetXp(int xp){
        Xp += xp;
        if (Xp >= Lvl*10){
            Xp = Lvl*10 - Xp;
            ++Lvl;
            Damage += 1 + Randomize::GetRand(0,1);
            HP += 1 + Randomize::GetRand(0,1);
            Armor += 1 + Randomize::GetRand(0,1);
            Intellect += 1 + Randomize::GetRand(0,1);
            MagicStrength += 1 + Randomize::GetRand(0,1);
            cout << "Вы получили новый уровень!! Текущий уровень - " << Lvl;
            // Todo: Реализовать выпадения 2-3 перков
        }
        return;
    }
};


#endif //UNTITLED3_HERO_H
