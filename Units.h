//
// Created by user on 11.03.2021.
//

#ifndef MAIN_CPP_UNITS_H
#define MAIN_CPP_UNITS_H
#include <iostream>
#include <string>
#include "Randomize.h"


using namespace std;

class Units {
private:
    string Race;
    string Name;
    int Damage;
    int HP;
    int Armor;
    int Amount = 1;
    int MaxAmount;
    int Cost;
public:

    string units[4][7] = {
            {"Люди","Лучник","5","5","2","1000","100"},
            {"Драконы","Беззубик","70","50","10","100","1000"},
            {"Тролли","Тролль-шаман","10","4","2","1000","200"},
            {"Существа","Феникс","90","120","15","20","1500"},
    };

    Units(){
        Name = "";
    }
    void AddUnits(string Race, string Name, string Damage, string HP, string Armor, string MaxAmount, int Cost )
    {
        this->Race = stoi(Race);
        this->Name = stoi(Name);
        this->Damage = stoi(Damage);
        this->HP = stoi(HP);
        this->Armor = stoi(Armor);
        this->MaxAmount = stoi(MaxAmount);
        this->Cost = Cost;
    }
    void BuyUnits(string name){
        for (int i = 0; i < size(units);i++){
            if (name == units[i][1]){
                Race = units[i][0];
                Name = units[i][1];
                Damage = stoi(units[i][2]);
                HP = stoi(units[i][3]);
                Armor = stoi(units[i][4]);
                MaxAmount = stoi(units[i][5]);
                Cost = stoi(units[i][6]);
                st:
                cout << "Введите количество юнитов: ";
                int amount;
                cin >> amount;
                if (amount < 1 || amount > MaxAmount){
                    cout << "Введено неверное значение";
                    goto st;
                }
            }
        }
    }
    vector<Units> FillMercenary(int type)
    {
        int costpercent;
        int length;
        bool est = false;
        vector<Units> mercenaries;
        switch (type)
        {
            case 0:
            {
                costpercent = 50;
                length = Randomize::GetRand(5,15);
            }
            case 1:
            {
                costpercent = 25;
                length = Randomize::GetRand(5,10);
            }
            case 2:
            {
                length = Randomize::GetRand(5,10);
                costpercent = 10;
            }
            case 3:
            {
                costpercent = 0;
                length = Randomize::GetRand(5,8);
            }
            case 4:
            {
                costpercent = -10;
                length = Randomize::GetRand(3,5);
            }
            case 5:
            {
                costpercent = -25;
                length = Randomize::GetRand(2,4);
            }
            case 6:
            {
                costpercent = -50;
                length = 1;
            }
            case 7:
            {
                costpercent = -75;
                length = 1;
            }

        }
        for (int i = 0; i<length; i++)
        {
            Units unit;
            int s = Randomize::GetRand(0,30);
            unit.AddUnits(units[s][0], units[s][1], units[s][2], units[s][3], units[s][4], units[s][5], stoi(units[s][6])+stoi(units[s][6])*(costpercent/100));
            for (int j = 0; j < length; j++)
            {
                if (mercenaries[i].GetName() == unit.GetName())
                    est = true;
                if (est == true)
                    break;
            }
            if (est == true)
                i--;
            else
                mercenaries.push_back(unit);
        }
        return mercenaries;
    }
    string GetRace(){
        return Race;
    }
    string GetName(){
        return Name;
    }
    int GetHP(){
        return HP;
    }
    void SetHp(int HP)
    {
        this->HP = HP;
    }
    int GetDamage(){
        return Damage;
    }
    int GetArmor(){
        return Armor;
    }
    int GetMaxAmount(){
        return MaxAmount;
    }
    void SetAmount( int amount)
    {
        this->Amount = amount;
    }
    int GetCost(){
        return Cost;
    }


};


#endif //MAIN_CPP_UNITS_H
