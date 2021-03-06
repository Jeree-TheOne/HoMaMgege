//
// Created by JerEe^ and Kosty on 01.03.2021.
//

#ifndef UNTITLED3_LOCATIONS_H
#define UNTITLED3_LOCATIONS_H
#include <windows.h>
#include <string>
#include <iostream>
#include <list>
#include "Perks.h"
#include "Randomize.h"
using namespace std;
class City {
private:
    string name;
    int type;
    bool inc[6] = {}; // <- Возможность возникновения в городе предприятий.
                      // inc[0] - Таверна, inc[1] - Рынок, inc[2] - Лагерь наемников,
                      // inc[3] - Башня мага, inc[4] - Магический колодец , inc[5] - Городская площадь.
public:
     const string CityName [3][10] = {
            {"Кёл", "Бер", "Ан", "Што", "Дал", "Бор", "Стар", "Лун", "Шат", "Мюн"},
            {"нинг", "дал", "ран", "бен", "лун", "мен", "арров", "страх", "кук", "муд"},
            {"град", "берг", "цин", "дор", "стан", "ленд", "пуль", "аббад", "вилль", "ока"}
    };
    enum TypeCity
    {
        VRich,
        Rich,
        GrowingUP,
        Medium,
        GrowingDown,
        Low,
        VeryLow,
        AfterRaid
    };
    City()
    {
        //int n1 = rand(0,9) ; Первая часть города
        //int n2 = Rand(0,9) ; Вторая часть города  Доделать рандом
        // int n3 = Rand(0,9) ; Третья часть города
        this->name = CityName[n1]+CityName[n2]+CityName[n3]; // <- Получение название горожа
        TypeCity test = static_cast<TypeCity>(rand() % 8);  // Рандом богатости города.
        this->type = test;//
        int ChanceINC1, ChanceINC2, ChanceINC3, ChanceINC4, ChanceINC5, ChanceINC6;
        switch (type)
        {
            case 0:
                {
                    ChanceINC1 = 10;
                    ChanceINC2 = 10;
                    ChanceINC3 = 10;
                    ChanceINC4 = 10;
                    ChanceINC5 = 7;
                    ChanceINC6 = 10;
                    break;
                }; // <- Шансы предприятия для VRich
            case 1:
            {
                ChanceINC1 = 10;
                ChanceINC2 = 9;
                ChanceINC3 = 8;
                ChanceINC4 = 8;
                ChanceINC5 = 5;
                ChanceINC6 = 9;
                break;
            }  // <- Шансы предприятия для Rich
            case 2:
            {
                ChanceINC1 = 10;
                ChanceINC2 = 9;
                ChanceINC3 = 7;
                ChanceINC4 = 5;
                ChanceINC5 = 3;
                ChanceINC6 = 5;
                break;
            }  // <- Шансы предприятия для GrowingUP
            case 3:
            {
                ChanceINC1 = 8;
                ChanceINC2 = 7;
                ChanceINC3 = 6;
                ChanceINC4 = 5;
                ChanceINC5 = 2;
                ChanceINC6 = 5;
                break;
            }  // <- Шансы предприятия для Medium
            case 4:
            {
                ChanceINC1 = 6;
                ChanceINC2 = 5;
                ChanceINC3 = 5;
                ChanceINC4 = 4;
                ChanceINC5 = 2;
                ChanceINC6 = 4;
                break;
            }  // <- Шансы предприятия для GrowingDown
            case 5:
            {
                ChanceINC1 = 5;
                ChanceINC2 = 4;
                ChanceINC3 = 2;
                ChanceINC4 = 0;
                ChanceINC5 = 0;
                ChanceINC6 = 2;
                break;
            }  // <- Шансы предприятия для Low
            case 6:
            {
                ChanceINC1 = 3;
                ChanceINC2 = 2;
                ChanceINC3 = 0;
                ChanceINC4 = 0;
                ChanceINC5 = 0;
                ChanceINC6 = 2;
                break;
            }  // <- Шансы предприятия для VLow
            case 7:
            {
                ChanceINC1 = 1;
                ChanceINC2 = 0;
                ChanceINC3 = 0;
                ChanceINC4 = 0;
                ChanceINC5 = 0;
                ChanceINC6 = 0;
                break;
            }  // <- Шансы предприятия для AfterRaid

        }

        }

    };
    void Show()
    {


    }

};

class Dungeon {
private:
};
class Outside {
private:
};


#endif //UNTITLED3_LOCATIONS_H
