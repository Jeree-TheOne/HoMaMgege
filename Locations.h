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
    bool inc[7]; // <- Возможность возникновения в городе предприятий.

public:
      string CityName [3][10] = {
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
         int n1 = Randomize::GetRand(0,9) ; //Первая часть города
         int n2 = Randomize::GetRand(0,9) ; //Вторая часть города  Доделать рандом
         int n3 = Randomize::GetRand(0,9) ; //Третья часть города
         this->name = CityName[0][n1] + CityName[1][n2] + CityName[2][n3]; // <- Получение название города
         TypeCity test = static_cast<TypeCity>(Randomize::GetRand(0,7));  // Рандом богатости города.
         this->type = test;//
         int ChanceINC[7];
        switch (type)
        {
            // inc[0] - Таверна, inc[1] - Рынок, inc[2] - Лагерь наемников,
            // inc[3] - Башня мага, inc[4] - Магический колодец , inc[5] - Городская площадь,
            // inc[6] - Торговец побрякушками, inc[7] - Шатер предсказательницы.
            case 0:
                {
                    ChanceINC[0] = 10;
                    ChanceINC[1] = 10;
                    ChanceINC[2] = 10;
                    ChanceINC[3] = 10;
                    ChanceINC[4] = 7;
                    ChanceINC[5] = 10;
                    ChanceINC[6] = 9;
                    ChanceINC[7] = 9;
                    break;
                }; // <- Шансы предприятия для VRich
            case 1:
            {
                ChanceINC[0] = 10;
                ChanceINC[1] = 10;
                ChanceINC[2] = 8;
                ChanceINC[3] = 8;
                ChanceINC[4] = 7;
                ChanceINC[5] = 10;
                ChanceINC[6] = 8;
                ChanceINC[7] = 8;
                break;
            }  // <- Шансы предприятия для Rich
            case 2:
            {
                ChanceINC[0] = 8;
                ChanceINC[1] = 9;
                ChanceINC[2] = 6;
                ChanceINC[3] = 7;
                ChanceINC[4] = 5;
                ChanceINC[5] = 8;
                ChanceINC[6] = 5;
                ChanceINC[7] = 5;
                break;
            }  // <- Шансы предприятия для GrowingUP
            case 3:
            {
                ChanceINC[0] = 6;
                ChanceINC[1] = 7;
                ChanceINC[2] = 4;
                ChanceINC[3] = 4;
                ChanceINC[4] = 2;
                ChanceINC[5] = 6;
                ChanceINC[6] = 4;
                ChanceINC[7] = 4;
                break;
            }  // <- Шансы предприятия для Medium
            case 4:
            {
                ChanceINC[0] = 6;
                ChanceINC[1] = 5;
                ChanceINC[2] = 3;
                ChanceINC[3] = 3;
                ChanceINC[4] = 2;
                ChanceINC[5] = 6;
                ChanceINC[6] = 3;
                ChanceINC[7] = 2;
                break;
            }  // <- Шансы предприятия для GrowingDown
            case 5:
            {
                ChanceINC[0] = 5;
                ChanceINC[1] = 5;
                ChanceINC[2] = 2;
                ChanceINC[3] = 1;
                ChanceINC[4] = 0;
                ChanceINC[5] = 4;
                ChanceINC[6] = 3;
                ChanceINC[7] = 0;
                break;
            }  // <- Шансы предприятия для Low
            case 6:
            {
                ChanceINC[0] = 3;
                ChanceINC[1] = 3;
                ChanceINC[2] = 0;
                ChanceINC[3] = 0;
                ChanceINC[4] = 0;
                ChanceINC[5] = 2;
                ChanceINC[6] = 1;
                ChanceINC[7] = 0;
                break;
            }  // <- Шансы предприятия для VLow
            case 7:
            {
                ChanceINC[0] = 1;
                ChanceINC[1] = 1;
                ChanceINC[2] = 1;
                ChanceINC[3] = 1;
                ChanceINC[4] = 1;
                ChanceINC[5] = 1;
                ChanceINC[6] = 1;
                ChanceINC[7] = 1;
                break;
            }  // <- Шансы предприятия для AfterRaid

        } // Определение шансов для выпадения предприятий.
        for(int i = 0; i<7; i++) // Просчет шанса выпадения
        {
            int array[10] = {0,0,0,0,0,0,0,0,0,0}; // Создается массив.
            for (int j = 0; j<ChanceINC[i]; j++) // ChanceINC - шанс выпадения данного здания.
                array[j] = 1; // Массив заполняется единичками ровно столько, сколько шанс выпадения здания.
            if (array[Randomize::GetRand(0,9)] == 1) // Вытягиваем на рандом число из того массива.
                this->inc[i] = true; // Если равен единице - присваеваем значение true.
        }

        }
        // TODO : Сделать определение зданий.

    void Show()
    {


    }
    }; // <- Класс города( Тут всё про город ).
class Dungeon {
private:
    string name;
    int type;
     list<int> shagi;
    int chdun[20] = {1,1,1,1,1,1,1,1,1,2,2,2,2,2,3,3,3,4,4,5}; // <- Возможность выпадения данжа
    // 1 - Gaybar (легко),
    // 2 - Leatherclub (средне),
    // 3 - Gym(Сложно),
    // 4 - MPT(Очень сложно),
    // 5 - Vangeon(Боссфайт).
public:
   const string DungeonName [3][10] = {
            {"Чёрный  ", "Зловещий ", "Скверный ", "Забытый ", "Замшелый ", "Мрачный ", "Чудовищный ", "Величавый ", "Заброшенный ", "Богом забытый "},
            {"gym ", "dungeon ", "техникум имени ", "leatherclub ", "gay bar ", "притон ", "склеп ", "погост ", "некрополь ", "bondage gay web-site "},
            {"Тёмного cum'a", "Даркохльма", "Районного прокурора", "Фистинг клаба", "fucking'х slaves", "horny dicks", "брошенных jabhronies", "унылых гачи-треков", "ВО РЭУ им. Г.В.Плеханова", "of latex gloves"}};

   Dungeon()
    {
        int n1 = Randomize::GetRand(0,9) ; //Первая часть названия данжа
        int n2 = Randomize::GetRand(0,9) ; //Вторая часть названия данжа
        int n3 = Randomize::GetRand(0,9) ; //Третья часть названия данжа
        this->name = DungeonName[0][n1] + DungeonName[1][n2] + DungeonName[2][n3]; // <- Получение название города
        this->type = chdun[Randomize::GetRand(0,19)];
        switch (type)
        {
            // 1 - Gaybar (легко),
            // 2 - Leatherclub (средне),
            // 3 - Gym(Сложно),
            // 4 - MPT(Очень сложно),
            // 5 - Vangeon(Боссфайт).
            // Задание последовательности и длительности прохождения данжа
            // Маркировка проходов.
            // 0 - Пустой проход. (Средний шанс)
            // 1 - Выход на улицу. (Маленький шанс)
            // 2 - Темная комната. (Маленький шанс)
            // После темной комнаты обязательно спавнится одна из следующих комнат!!!
            // 20 - Темная комната -> пустая комната. (Высокий шанс).
            // 21 -  Темная комната -> комната с ловушкой. (Средний шанс).
            // 22 -  Темная комната -> комната со средней наградой. (Средний шанс).
            // 23 -  Темная комната -> комната с  большой наградой. (маленький шанс).
            // 24 -  Темная комната -> комната со смертносной ловушкой. (очень маленький шанс).
            // 3 - Ловушка (маленький шанс) (Потеря одного из артефактов(средний шанс) ИЛИ потеря части юнитов (средний шанс) ИЛИ смерть гг(очень маленький шанс))
            // 4 - Вражеские юниты (средний шанс) Внимание! Градация идет от уровня данжа. (Слабые (Маленький шанс), Средние - (Высокий шанс), Сложые (маленький шанс).
            // 5 - Сундук (низкий шанс) (Маленькая награда (Высокий шанс), Средняя награда (маленький шанс), Большая награда (очень маленький шанс))
            // 6 - Босс данжа (СМ Поле Type).
            case 1:
            {
                bool Chance [6][10] = {
                        {true, true, true, true, true, true, false, false, false, false}, /*  Шанс пустой комнаты. */
                        {true, false, false, false, false, false, false, false, false, false}, /*  Шанс Выхода на улицу */
                        {true, false, false, false, false, false, false, false, false, false}, /*  Шанс Тёмной комнаты */
                        {true, true, true, true, false, false, false, false, false, false}, /* Шанс ловушки */
                        {true, true, true, true, true, true, false, false, false, false}, /*  Шанс врагов */
                        {true, true, true, false, false, false, false, false, false, false} /* Шанс сундук */
                         };

                int j = Randomize::GetRand(3,5);

            }
            case 2:
            {
                bool Chance [6][10] = {
                        {true, true, true, false, false, false, false, false, false, false}, /*  Шанс пустой комнаты. */
                        {true, false, false, false, false, false, false, false, false, false}, /*  Шанс Выхода на улицу */
                        {true, true, true, false, false, false, false, false, false, false}, /*  Шанс Тёмной комнаты */
                        {true, true, true, true, true, true, false, false, false, false}, /* Шанс ловушки */
                        {true, true, true, true, true, true, true, false, false, false}, /*  Шанс врагов */
                        {true, true, true, true, false, false, false, false, false, false} /* Шанс сундук */
                };
                int j = Randomize::GetRand(4,6);
            }
            case 3:
            {
                bool Chance [6][10] = {
                        {true, true, false, false, false, false, false, false, false, false}, /*  Шанс пустой комнаты. */
                        {true, false, false, false, false, false, false, false, false, false}, /*  Шанс Выхода на улицу */
                        {true, true, true, true, true, false, false, false, false, false}, /*  Шанс Тёмной комнаты */
                        {true, true, true, true, true, true, false, false, false, false}, /* Шанс ловушки */
                        {true, true, true, true, true, true, true, true, true, false}, /*  Шанс врагов */
                        {true, true, true, true, true, true, true, true, false, false} /* Шанс сундук */
                };
                int j = Randomize::GetRand(6,10);
            }
            case 4:
            {
                bool Chance [6][10] = {
                        {true, false, false, false, false, false, false, false, false, false}, /*  Шанс пустой комнаты. */
                        {true, false, false, false, false, false, false, false, false, false}, /*  Шанс Выхода на улицу */
                        {true, true, true, true, true, true, true, true, false, false}, /*  Шанс Тёмной комнаты */
                        {true, true, true, true, true, true, true, true, true, false}, /* Шанс ловушки */
                        {true, true, true, true, true, true, true, true, true, false}, /*  Шанс врагов */
                        {true, true, true, true, true, true, true, true, true, false} /* Шанс сундук */
                };
                int j = Randomize::GetRand(10,15);
            }
            case 5:
            {

                //20
            }
        }
    };



}; // <- Класс Данжена( Тут всё про данж ).
class Outside {
private:
}; // <- Класс Аутсайда( Тут всё про пересеченную местность ).


#endif //UNTITLED3_LOCATIONS_H
