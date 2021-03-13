//
// Created by user on 11.03.2021.
//

#ifndef MAIN_CPP_UNITS_H
#define MAIN_CPP_UNITS_H
#include <iostream>
#include <string>
#include "Randomize.h"
#include "Spells.h"


using namespace std;

class Units {
private:
    string Race;
    string Name;
    int Damage;
    int HP;
    int Armor;
    int Amount = 2;
    int MaxAmount;
    int Cost;
    int RemainsHP = 0;
public:
    vector<Spells> Buffs;
    string units[39][7] = {
            {"Люди","Лучник","6","5","2","1000","110"},
            {"Люди","Воин","5","8","4","1000","100"},
            {"Люди","Волшебник","8","3","1","1000","120"},
            {"Полурослики","Снайпер","8","3","2","1000","125"},
            {"Полурослики","Задира","4","4","4","1000","70"},
            {"Полурослики","Колдун","6","2","0","1000","80"},
            {"Дренеи","Копейщик","8","15","10","1000","230"},
            {"Дренеи","Заклинатель","12","5","5","1000","200"},
            {"Дренеи","Чернокнижник","15","10","4","1000","235"},
            {"Дроу","Лучница","20","12","5","1000","350"},
            {"Дроу","Чародей","25","10","4","1000","400"},
            {"Дроу","Убийца","45","15","8","1000","500"},
            {"Тренты","Энт-защитник","40","80","20","1000","1000"},
            {"Тренты","Энт-чародей","70","40","15","1000","1200"},
            {"Тренты","Энт-разведчик","20","40","10","1000","600"},
            {"Демоны","Пожиратель душ","50","20","10","100","700"},
            {"Демоны","Чернокнижник","70","15","5","100","750"},
            {"Демоны","Люцифер","140","70","50","10","2500"},
            {"Существа","Боевой единорог","90","100","15","100","1500"},
            {"Существа","Грифон","120","70","20","100","1750"},
            {"Существа","Минотавр","120","100","70","20","2000"},
            {"Драконы","Лятучая лягушка","70","50","10","100","1100"},
            {"Драконы","Хрустальная виверна","110","30","5","100","1200"},
            {"Драконы","Дневная фурия","75","40","7","100","1000"},
            {"Машины","Катапульта","75","90","20","1","2000"},
            {"Машины","Турель деда из овервотча","120","120","40","1","3000"},
            {"Машины","Swehrer Panzerspähwagen sieben Komma fünf Zentimeter Sonderkraftfahrzeug zweihundertvierunddreissig vier Panzerabwehrkanonenwagen","10000","10000","5000","1","50000"},
            {"Аниме","Наруто","250","250","70","100","4500"},
            {"Аниме","Саске","2500","2500","70","1","25000"},
            {"Аниме","Мадара","10000","10000","500","1","50000"},
            {"Элементали","Каменный голем","100","300","50","100","3500"},
            {"Элементали","Ледяной дух","250","100","40","100","3100"},
            {"Элементали","Феникс","350","350","70","10","6700"},
            {"Лягушки","Жаба Клава","170","350","70","100","4500"},
            {"Лягушки","Лягушка номер два","250","450","80","100","5400"},
            {"лягушки","Лягушка номер три","900","700","120","10","12500"},
            {"Гачисты","Slave","10","10","10","10000","10"},
            {"Гачисты","Van Darkholme (Машина)","10000","10000","5000","1","50000"},
            {"Гачисты","Billy Herrington (Танк)","10000","10000","5000","1","50000"}
    };

    Units(){
        Name = "";
    }
    ~Units()
    {

    }
    void AddUnits(string race, string name, string damage, string hp, string armor, string maxAmount, int cost )
    {
        Race = stoi(race);
        Name = stoi(name);
        Damage = stoi(damage);
        HP = stoi(hp);
        Armor = stoi(armor);
        MaxAmount = stoi(maxAmount);
        Cost = cost;
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
                /*st:
                cout << "Введите количество юнитов: ";
                int amount;
                cin >> amount;
                if (amount < 1 || amount > MaxAmount){
                    cout << "Введено неверное значение";
                    goto st;
                }*/
                break;
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

    void ArmyGetDamage(int damage){
        if (!this->Buffs.empty())
        {
            for (Spells a: Buffs)
            {
                if (a.GetSpell()[0] == "Curse")
                {
                    damage = (damage * 2)/3 + damage;
                }
              else  if (a.GetSpell()[0] == "Fireshield")
                {
                    damage = damage - (damage * 25)/100 ;
                }
                else  if (a.GetSpell()[0] == "Wikness")
                {
                    damage = damage + (damage * 10)/100;
                }
                else  if (a.GetSpell()[0] == "WaterDefence")
                {
                    damage = damage - (damage * 15)/100;
                }
                else  if (a.GetSpell()[0] == "StoneSkin")
                {
                    damage = damage - (damage * 30)/100;
                }
                else  if (a.GetSpell()[0] == "DirtDefence")
                {
                    damage = damage - (damage * 15)/100;
                }
                else  if (a.GetSpell()[0] == "Accuracy")
                {
                    damage = damage - (damage * 15)/100;
                }
                else  if (a.GetSpell()[0] == "Lucky")
                {
                    damage = damage - (damage *(Randomize::GetRand(0,1)) * 50)/100;
                }
            }
        }
        if (damage >= (HP * Amount + RemainsHP)+ Armor*1.05) {
            Name = "";
            return;
        }
        if (RemainsHP == 0) {
            int KilledUnits = damage / HP;
            RemainsHP = damage % HP;
            Amount -= KilledUnits;
        }
        else{
            int TotalHp = (Amount-1) * HP + RemainsHP;
            TotalHp -= damage;
            Amount = TotalHp / HP;
            RemainsHP = TotalHp % HP;
        }
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
    int GetAmount(){
        return  Amount;
    }
    void SetHp(int hp)
    {
        HP = hp;
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
