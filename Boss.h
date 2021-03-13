//
// Created by user on 13.03.2021.
//

#ifndef MAIN_CPP_BOSS_H
#define MAIN_CPP_BOSS_H
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Boss {
    string bosses[5][4]={
            {"Камень","100","500","40"},//В последнюю яейку надо запихнуть рисунок
            {"Лягушка-квакушка","250","1200","60"},
            {"Рад.фемка","400","2000","60"},
            {"Учиха Мадара","1000","5000","120"},
            {"Van Darkholme","10000","20000","250"}
    };
    string Name;
    int Damage;
    int HP;
    int Armor;
    string Picture[9];
public:
    Boss(int Hardness){
        Name = bosses[Hardness-1][0];
        Damage = stoi(bosses[Hardness-1][1]) ;
        HP = stoi(bosses[Hardness-1][2]);
        Armor = stoi(bosses[Hardness-1][3]);
        if (Hardness == 1){

        }
    }
    string GetName(){
        return Name;
    }
    int GetDamage(){
        return  Damage;
    }
    int GetHP(){
        return  HP;
    }
    int GetArmor(){
        return  Armor;
    }

    void BossGetDamage(int damage){
        damage -= Armor;
        if (damage >= HP)
            HP = 0;
        else
            HP -= damage;
    }
};


#endif //MAIN_CPP_BOSS_H
