//
// Created by user on 12.03.2021.
//

#ifndef MAIN_CPP_BATTLE_H
#define MAIN_CPP_BATTLE_H


#include "Hero.h"
#include <string>
#include <iostream>
#include <iomanip>

class Battle {
public:
    Hero *Enemy = new Hero(1);
    void StartBattle(Hero hero){
        system("cls");
        ShowArmy(hero);
    }
    void SetEnemy(Hero enemy){
        *Enemy = enemy;
    }
    void ShowArmy(Hero hero){
        cout << "\tВы:" << setw(123) << "Ваш противник:\n";
        string name1, name2,res;
        for (int i = 0; i < 10; i++){
            if (hero.army[i].GetName() == "")
                name1 = to_string(i+1) + ") Пусто";
            else
                name1 = to_string(i + 1) + ") " + hero.army[i].GetName() + ", Урон: " + to_string(hero.army[i].GetDamage() * hero.army[i].GetAmount()) +  ", Здоровье: " +to_string( hero.army[i].GetHP() * hero.army[i].GetAmount()) +", Броня: " + to_string( hero.army[i].GetArmor());
            if (Enemy->army[i].GetName() == "")
                name2 = to_string(i+1) + ") Пусто";
            else
                name2 = to_string(i + 1) + ") " + Enemy->army[i].GetName() + ", Урон: " + to_string(Enemy->army[i].GetDamage() * Enemy->army[i].GetAmount()) +  ", Здоровье: " +to_string( Enemy->army[i].GetHP() * Enemy->army[i].GetAmount()) +", Броня: " + to_string( Enemy->army[i].GetArmor());
            cout <<"\t"<<left << setw(100 + (size(name1)/2.85)) << name1 << right  << name2  << endl;
        }
    }
};


#endif //MAIN_CPP_BATTLE_H
