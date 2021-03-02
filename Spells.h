//
// Created by kosty on 02.03.2021.
//

#ifndef MAIN_CPP_SPELLS_H
#define MAIN_CPP_SPELLS_H
#include <iostream>
using namespace std;
class Spells {

protected:
    string Name; // Название
    string Stih; // Стихия заклинания (Всего 4 - Земля, Огонь, Вода, Воздух).
    string Type; // Тип (дамажный, антимагический, усиляющий, разум).
    string Distance; // Дистанция заклинания (Один/ауе/все персонажи).
    string Duration; // Длительность заклинания
    string Level; // Уровень заклинания.
    string Cost; // Цена в маны
public:
    void SpellADD (string name) // Добавление заклинание через массив данных о заклинаниях.
    {

    }
};
class DSpell : Spells
{
private: int Damage;
public:
    void SetDSpell(string name, string stih, string type, string distance, string level, string cost, string duration, int damage){
        Name = name;
        Stih = stih;
        Type = type;
        Distance = distance;
        Level = level;
        Cost = cost;
        Duration = duration;
        Damage = damage;
    }

}; // Дамажные заклинания

class ASpell : Spells
{

}; // Антимагические заклинания
class BSpell : Spells
{

}; // Усиляющие заклинания
class MSpell : Spells
{

}; // Разумные заклинания





#endif //MAIN_CPP_SPELLS_H
