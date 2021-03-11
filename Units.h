//
// Created by user on 11.03.2021.
//

#ifndef MAIN_CPP_UNITS_H
#define MAIN_CPP_UNITS_H
#include <iostream>
#include <string>

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
    string GetName(){
        return Name;
    }
};


#endif //MAIN_CPP_UNITS_H
