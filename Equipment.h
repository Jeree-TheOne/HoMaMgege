//
// Created by JerEe^ on 01.03.2021.
//

#ifndef UNTITLED3_EQUIPMENT_H
#define UNTITLED3_EQUIPMENT_H
#include <iostream>
#include <list>
#include "Format.h"

using namespace std;

enum Type{
    Helmet,
    Amulet,
    ChestArmor,
    LeftHand,       //shit
    RightHand,      //morgenshtern
    Ring,
    Nogi,
    Pet,
    Access
};



class Equipment {
private:
    string Name;
    string Type;
    string Stats;
public:

    const string equipment[36][3] = {
            {"Ведро ","Helmet","1_0_4_0_0_200"}, // Damage_HP_Armor_Intellect_MagicStrength_Gold
            {"Шлем варваров ","Helmet","12_0_14_0_0_1500"},
            {"Шапка-ушанка ","Helmet","20_0_30_10_5_5000"},
            {"Резиновый *** ","Helmet","100_0_200_50_50_25000"},
            {"Кандалы ","Amulet","4_0_0_0_0_200"},
            {"Ошейник Дьявола ","Amulet","25_0_6_5_10_1500"},
            {"Цепь Сигурда ","Amulet","25_0_20_0_10_5000"},
            {"Чокер ","Amulet","80_0_150_0_0_1500"},
            {"Алмазный нагрудник ","ChestArmor","0_0_10_0_1_300"},
            {"\"Ребра\" ","ChestArmor","20_0_20_0_0_2000"},
            {"Кожак ","ChestArmor","30_0_50_10_10_5500"},
            {"Худи с Мадарой ","ChestArmor","200_0_350_30_30_35000"},
            {"Дверь с ручкой ","LeftHand","1_0_6_0_0_250"},
            {"Стальной щит ","LeftHand","10_0_30_3_3_2500"},
            {"Щит героя ","LeftHand","15_0_50_20_15_6000"},
            {"Настоящий SHIT ","LeftHand","50_0_300_30_30_2000"},
            {"Дубинка \"bonk\" ","RightHand","5_0_1_0_0_300"},
            {"Меч Сияние ","RightHand","10_0_5_0_0_2500"},
            {"Лазерный меч ","RightHand","50_0_20_0_0_5500"},
            {"Latex Glove ","RightHand","250_0_100_0_0_25000"},
            {"Кольцо лоха ","Ring","2_0_3_2_2_400"},
            {"Кольцо жизненной силы ","Ring","3_0_6_6_6_1700"},
            {"Перстень колдуна ","Ring","5_0_15_15_15_5650"},
            {"Кольцо Всевластия " ,"Ring","10_0_50_65_65_19500"},
            {"Портянки ","Nogi","2_0_2_0_0_150"},
            {"Сандали с носками ","Nogi","4_0_6_-5_0_1200"},
            {"Air Force 1 ","Nogi","10_0_20_10_5_4800"},
            {"Ботинки Саника ","Nogi","40_0_150_15_15_19000"},
            {"Грязная тряпка ","Access","2_0_2_0_0_200"},
            {"Повязка Тупака ","Access","10_0_8_5_8_1450"},
            {"Bondage ","Access","25_0_35_10_10_3500"},
            {"Повязка Рикардо Милоса ","Access","150_0_200_100_100_27000"}
    };


    Equipment(string name, string type, string stats ){
        this->Name = name;
        this->Type = type;
        this->Stats = stats;
    }
    void DropEquipment(int index){
        cout << "Вам выпал новый предмет: " << equipment[index][0]<<endl;
        cout << "Его характеристики: \n" << Format::DeFormat(equipment[index][2]) << "\n";
        ch:
        cout << "Ваши действия: \n1) Надеть новый предмет \n2) Положить в инвентарь\nВыберите действие: ";
        int action;
        cin >> action;
        if (action == 1)
            EquipEquipment(equipment[index][0]);
        else if (action == 2)
            AddToInventory(equipment[index][0]);
        else{
            cout<<"Введено неверное значение";
            goto ch;
        }
    }

    void EquipEquipment(string name){

    }

    void AddToInventory(string name){

    }
};


#endif //UNTITLED3_EQUIPMENT_H
