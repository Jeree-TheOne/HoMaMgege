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
        ShowArmy(hero, *Enemy);
        while (true){
            for (int i = 0; i < 10; i++){
                if (hero.army[i].GetName() == "" || Enemy->army[i].GetName() == "")
                    break;
            }
            bool turn = true;
            if (Randomize::GetRand(0,1) == 0) turn = false;
            if (turn == true){
                cout << "Ваш ход\n";
                for (int i = 0; i < 10; i++){
                    if (hero.army[i].GetName() == "") continue;
                    cout << "Сейчас атакует армия "<< i+1 <<"\nВведите номер армии противника, которую они будут атаковать: ";
                    st:
                    int num;
                    cin >> num;
                    if (num > 10 || num < 1 || Enemy->army[num - 1].GetName() == ""){
                        cout << "\nВведено неверное значение\n";
                        goto st;
                    }
                    Enemy->army[num].ArmyGetDamage(hero.army[i].GetDamage() * hero.army[i].GetAmount());
                }
            }
            else{
                cout << "Ход противника\n";
                for (int i = 0; i < 10; i++){
                    if (Enemy->army[i].GetName() == "") continue;
                    st1:
                    int num = Randomize::GetRand(0,9);
                    if (hero.army[num].GetName() == "")
                        goto st1;
                    hero.army[1].ArmyGetDamage(Enemy->army[i].GetDamage() * Enemy->army[i].GetAmount());
                }
            }
            break;
        }
    }
    void SetEnemy(Hero enemy){
        *Enemy = enemy;
    }
    void ShowArmy(Hero hero, Hero enemy){
        cout << "\tВы:" << setw(123) << "Ваш противник:\n";
        string name1, name2,res;
        for (int i = 0; i < 10; i++){
            if (hero.army[i].GetName() == "")
                name1 = to_string(i+1) + ") Пусто";
            else
                name1 = to_string(i + 1) + ") " + hero.army[i].GetName() + ", Урон: " + to_string(hero.army[i].GetDamage() * hero.army[i].GetAmount()) +  ", Здоровье: " +to_string( hero.army[i].GetHP() * hero.army[i].GetAmount()) +", Броня: " + to_string( hero.army[i].GetArmor());
            if (enemy.army[i].GetName() == "")
                name2 = to_string(i+1) + ") Пусто";
            else
                name2 = to_string(i + 1) + ") " + enemy.army[i].GetName() + ", Урон: " + to_string(enemy.army[i].GetDamage() * enemy.army[i].GetAmount()) +  ", Здоровье: " +to_string( enemy.army[i].GetHP() * enemy.army[i].GetAmount()) +", Броня: " + to_string( enemy.army[i].GetArmor());
            cout <<"\t"<<left << setw(100 + (size(name1)/2.85)) << name1 << right  << name2  << endl;
        }
    }
};


#endif //MAIN_CPP_BATTLE_H
