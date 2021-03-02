//
// Created by kosty on 02.03.2021.
//

#ifndef MAIN_CPP_SPELLS_H
#define MAIN_CPP_SPELLS_H
#include <iostream>
using namespace std;
class Spells {

private:
    string Name; // Название
    string Type; // Тип (дамажный, антимагический, усиляющий, разум).
    string Cost; // Цена в мане
    string Disctance; // Дистанция заклинания (Один/ауе/все персонажи).
    string Level; // Уровень заклинания.
    string Stih; // Стихия заклинания (Всего 4 - Земля, Огонь, Вода, Воздух).
    string ALLSPELLS[16][7] = {
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},

    }; // инициализация всех перков

public:
    void SpellADD (string name) // Добавление заклинание через массив данных о заклинаниях.
    {

    }


};


#endif //MAIN_CPP_SPELLS_H
