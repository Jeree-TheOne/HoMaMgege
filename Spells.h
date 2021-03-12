//
// Created by kosty on 02.03.2021.
//

#ifndef MAIN_CPP_SPELLS_H
#define MAIN_CPP_SPELLS_H
#include <iostream>
#include "Randomize.h"
#include <string>
using namespace std;
class Spells {

protected:
    string Name; // Название
    string Stih; // Стихия заклинания (Всего 4 - Земля, Огонь, Вода, Воздух).
    string Type; // Тип (дамажный, антимагический, усиляющий, разум).
    int Damage;
    int Distance; // Дистанция заклинания (Один/ауе/все персонажи).
    int Duration; // Длительность заклинания
    int Level; // Уровень заклинания.
    int Cost; // Цена в маны
public:
    // (1 - дамаг, 2 - Разум, 3 - баф/дебаф, 4 -  магия/антимагия)
    // Огненные *Fireball(фаерболл), *Blind(Слепота), *Curse(Проклятие), *Fireshield(Огненный щит);
    // Водные *Icearrow(ледянная стрела), *Clone(Клон), *Wikness(Слабость), *Waterdefence(Защита от магии воды);
    // Земля *Boom(Взрыв), *EarthElemental, *StoneSkin(Каменная кожа), *DirtDefence(Защита от магии земли);
    // Воздух. *Сhainzipper(Цепная молния), *Accuracy(Точность), *Lucky(Удача), *Dimensiondoor(Дверь измерений)
    //static Spells Clone, Weakness, Waterdefence, Blind, Curse, Fireshield, UndeadDead, StoneSkin, DirtDefence, Accuracy, Lucky, Dimensiondoor, Fireball, Icearrow, boom, Chainzipper;
    string spells[16][8] = {
            { "Fireball", "Fire", "Damage", "30", "1", "1", "1", "15" },
            { "Blind", "Fire", "Mind", "0", "1", "3", "3", "15" },
            { "Curse", "Fire", "Buff", "0", "1", "3", "2", "10" },
            { "Fireshield", "Fire", "Magic", "0", "1", "3", "4", "15" },
            { "Icearrow", "Water", "Damage", "15", "1", "1", "2", "8" },
            { "Clone", "Water", "Mind", "0", "1", "3", "5", "25" },
            { "Wikness", "Water", "Buff", "0", "1", "3", "1", "5" },
            { "WaterDefence", "Water", "Magic", "0", "1", "3", "2", "8" },
            { "Boom", "Earth", "Damage", "200", "1", "1", "10", "40" },
            { "EarthElemental", "Earth", "Mind", "0", "1", "1", "8", "50" },
            { "StoneSkin", "Earth", "Buff", "0", "1", "3", "2", "10" },
            { "DirtDefence", "Earth", "Magic", "0", "1", "3", "4", "10" },
            { "Chainzippper", "Air", "Damage", "50", "3", "1", "10", "50" },
            { "Accuracy", "Air", "Mind", "0", "1", "3", "2", "10" },
            { "Lucky", "Air", "Buff", "0", "1", "3", "3", "15" },
            { "Dimensiondoor", "Air", "Magic", "0", "0", "1", "10", "150" }
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
           Cost =  stoi(spells[jj][7]);
    }
    string* GetSpell()
    {
        string a[8]  = {Name, Stih, Type, to_string(Damage), to_string(Distance), to_string(Duration), to_string(Level), to_string(Cost)};
        return a;
    }

};








#endif //MAIN_CPP_SPELLS_H
