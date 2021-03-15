//
// Created by JerEe^ on 01.03.2021.
//

#ifndef UNTITLED3_EQUIPMENT_H
#define UNTITLED3_EQUIPMENT_H
#include <iostream>
#include <vector>
#include <list>
#include "Format.h"
#include "Randomize.h"
using namespace std;

enum Type{
    Helmet = 1,
    Amulet,
    ChestArmor,
    LeftHand,       //shit
    RightHand,      //morgenshtern
    Ring,
    Nogi,
    Pet,
    Access
};


class In;

class Equipment {
private:
    string Name = "";
    string Type = "";
    string Stats = "";
public:
    string equipment[36][3] = {
            {"Ведро ","Шлем","1_0_4_0_0_200"}, // Damage_HP_Armor_Intellect_MagicStrength_Gold
            {"Шлем варваров ","Шлем","12_0_14_0_0_1500"},
            {"Шапка-ушанка ","Шлем","20_0_30_10_5_5000"},
            {"Резиновый *** ","Шлем","100_0_200_50_50_25000"},
            {"Кандалы ","Амулет","4_0_0_0_0_200"},
            {"Ошейник Дьявола ","Амулет","25_0_6_5_10_1500"},
            {"Цепь Сигурда ","Амулет","25_0_20_0_10_5000"},
            {"Чокер ","Амулет","80_0_150_0_0_1500"},
            {"Алмазный нагрудник ","Нагрудник","0_0_10_0_1_300"},
            {"\"Ребра\" ","Нагрудник","20_0_20_0_0_2000"},
            {"Кожак ","Нагрудник","30_0_50_10_10_5500"},
            {"Худи с Мадарой ","Нагрудник","200_0_350_30_30_35000"},
            {"Дверь с ручкой ","Левая рука","1_0_6_0_0_250"},
            {"Стальной щит ","Левая рука","10_0_30_3_3_2500"},
            {"Щит героя ","Левая рука","15_0_50_20_15_6000"},
            {"Настоящий SHIT ","Левая рука","50_0_300_30_30_2000"},
            {"Дубинка \"bonk\" ","Правая рука","5_0_1_0_0_300"},
            {"Меч Сияние ","Правая рука","10_0_5_0_0_2500"},
            {"Лазерный меч ","Правая рука","50_0_20_0_0_5500"},
            {"Latex Glove ","Правая рука","250_0_100_0_0_25000"},
            {"Кольцо лоха ","Кольцо","2_0_3_2_2_400"},
            {"Кольцо жизненной силы ","Кольцо","3_0_6_6_6_1700"},
            {"Перстень колдуна ","Кольцо","5_0_15_15_15_5650"},
            {"Кольцо Всевластия " ,"Кольцо","10_0_50_65_65_19500"},
            {"Портянки ","Ноги","2_0_2_0_0_150"},
            {"Сандали с носками ","Ноги","4_0_6_-5_0_1200"},
            {"Air Force 1 ","Ноги","10_0_20_10_5_4800"},
            {"Ботинки Саника ","Ноги","40_0_150_15_15_19000"},
            {"Кошка ","Питомец","4_0_0_2_2_350"},
            {"Уитли ","Питомец","10_0_0_8_8_1700"},
            {"Билл Шифр ","Питомец","15_0_5_20_20_3500"},
            {"Плотва ","Питомец","50_0_50_150_150_22000"},
            {"Грязная тряпка ","Аксессуар","2_0_2_0_0_200"},
            {"Повязка Тупака ","Аксессуар","10_0_8_5_8_1450"},
            {"Bondage ","Аксессуар","25_0_35_10_10_3500"},
            {"Повязка Рикардо Милоса ","Аксессуар","150_0_200_100_100_27000"}
    };
    Equipment(){

    };
    void AddEquipment(string Name, string Type, string Stats)
    {
        this->Name = Name;
        this->Type = Type;
        this->Stats = Stats;
    }
    void NewEquipment(){
        int rare;
        int index = Randomize::GetRand(1,100);
        if (index <= 65)
            rare = 0;
        else if(index <= 90)
            rare = 1;
        else if(index <= 99)
            rare = 2;
        else
            rare = 3;
        int slot = Randomize::GetRand(0,8);
        Name = equipment[slot*4 + rare][0];
        Type = equipment[slot*4 + rare][1];
        Stats = equipment[slot*4 + rare][2];
    }

    int DropEquipment(){
        NewEquipment();
        cout << "Вам выпал новый предмет: " << Name <<endl;
        cout << "Слот: " << Type <<endl;
        cout << "Его характеристики: \n" << Format::DeFormat(Stats) << "\n";
        ch:
        cout << "Ваши действия: \n1) Надеть новый предмет \n2) Положить в инвентарь\nВыберите действие: ";
        int action;
        cin >> action;
        if (action == 1)
            return 1;
        else if (action == 2)
            return 2;
        else{
            cout<<"Введено неверное значение\n";
            goto ch;
        }
    }
    string GetType(){
        return Type;
    }
    string GetName(){
        return Name;
    }
    string GetStats(){
        return Stats;
    }
};


#endif //UNTITLED3_EQUIPMENT_H
