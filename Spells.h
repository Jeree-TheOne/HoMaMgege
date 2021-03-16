//
// Created by kosty on 02.03.2021.
//

#ifndef MAIN_CPP_SPELLS_H
#define MAIN_CPP_SPELLS_H
#include <iostream>
#include "Randomize.h"
#include <string>
using namespace std;
class Spells
        {

protected:
    string Name; // Название
    string Stih; // Стихия заклинания (Всего 4 - Земля, Огонь, Вода, Воздух).
    string Type; // Тип (дамажный, антимагический, усиляющий, разум).
    int Damage;
    int Distance; // Дистанция заклинания (Один/ауе/все персонажи).
    int Duration; // Длительность заклинания
    int Level; // Уровень заклинания.
    int MCost; // Цена в маны
    int GCost; // Цена голды
public:
    // (1 - дамаг, 2 - Разум, 3 - баф/дебаф, 4 -  магия/антимагия)
    // Огненные *Fireball(фаерболл), *Blind(Слепота), *Curse(Проклятие), *Fireshield(Огненный щит);
    // Водные *Icearrow(ледянная стрела), *Clone(Клон), *Wikness(Слабость), *Waterdefence(Защита от магии воды);
    // Земля *Boom(Взрыв), *EarthElemental, *StoneSkin(Каменная кожа), *DirtDefence(Защита от магии земли);
    // Воздух. *Сhainzipper(Цепная молния), *Accuracy(Точность), *Lucky(Удача), *Dimensiondoor(Дверь измерений)
    string spells[14][9] = {
            { "Fireball", "Fire", "Damage", "30", "1", "1", "1", "15", "250" },
            { "Blind", "Fire", "Mind", "0", "1", "3", "3", "15", "800" },
            { "Curse", "Fire", "Buff", "0", "1", "3", "2", "10", "600" },
            { "Fireshield", "Fire", "Magic", "0", "1", "3", "4", "15", "900" },
            { "Icearrow", "Water", "Damage", "15", "1", "1", "2", "8", "300" },
            /*{ "Clone", "Water", "Mind", "0", "1", "3", "5", "25", "3000" },*/
            { "Wikness", "Water", "Buff", "0", "1", "3", "1", "5", "300" },
            { "WaterDefence", "Water", "Magic", "0", "1", "3", "2", "8", "250" },
            { "Boom", "Earth", "Damage", "500", "1", "1", "10", "40", "5000" },
        //    { "EarthElemental", "Earth", "Mind", "0", "1", "1", "8", "50", "5000" },
            { "StoneSkin", "Earth", "Buff", "0", "1", "3", "2", "10", "250" },
            { "DirtDefence", "Earth", "Magic", "0", "1", "3", "4", "10", "300" },
            { "Chainzippper", "Air", "Damage", "50", "3", "1", "10", "6000" },
            { "Accuracy", "Air", "Mind", "0", "1", "3", "2", "10", "1000" },
            { "Lucky", "Air", "Buff", "0", "1", "3", "3", "15", "600" },
            { "Dimensiondoor", "Air", "Magic", "0", "0", "1", "10", "150", "9000"}
    };
    Spells()
    {
       int jj = Randomize::GetRand(0,15);
           Name = spells[jj][0];
           Stih = spells[jj][1];
           Type = spells[jj][2];
           Damage = stoi(spells[jj][3]);
           Distance =  stoi(spells[jj][4]);
           Duration =  stoi(spells[jj][5]);
           Level =  stoi(spells[jj][6]);
           MCost =  stoi(spells[jj][7]);
           GCost = stoi(spells[jj][8]);
    }
    void SetDuration(int duration)
    {
        Duration = duration;
    }

    //Name, Stih, Type, to_string(Damage), to_string(Distance), to_string(Duration), to_string(Level), to_string(MCost), to_string(GCost)
    string GetName()
    {
        return Name;
    }
    string GetStih(){
        return Stih;
    }
    string GetType(){
        return Type;
    }
    int GetDamage(){
        return Damage;
    }
    int GetDistance(){
        return Distance;
    }
    int GetDuration(){
        return Duration;
    }
    int GetLevel(){
        return Level;
    }
    int GetMCost(){
        return MCost;
    }
    int GetCost()
    {
        return this->GCost;
    }
    void SetCost(int cost)
    {
        this->GCost = cost;
    }

    vector<Spells>FillSpells(int type)
    {
        int costpercent;
        int length;
        vector<Spells> spells;
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
            povtor:
            Spells spell;
            spell.SetCost(spell.GetCost()+spell.GetCost()*costpercent/100);
            if (!spells.empty())
            for (int j = 0; j < length; j++)
            {
                if (spell.GetName() == spells[i].GetName())
                    goto povtor;
            }

                spells.push_back(spell);
        }
        return spells;
    }

};









#endif //MAIN_CPP_SPELLS_H
