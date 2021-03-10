//
// Created by Kosty on 01.03.2021.
//

#ifndef UNTITLED3_LOCATIONS_H
#define UNTITLED3_LOCATIONS_H
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "Perks.h"
#include "Randomize.h"
#include "Enterprises.h"
#include "Hero.h"
using namespace std;
class City {
private:
    string name;
    int type;
    bool inc[7]; // <- Возможность возникновения в городе предприятий.
    vector<Enterprise> enterprises; // сами предприятия

public:
      string CityName [3][10] = {
            {"Кёл", "Билли", "Ан", "Кам", "Дик", "Лезер", "Стар", "Лун", "Шат", "Мюн"},
            {"нинг", "дал", "ран", "бен", "лун", "мен", "арров", "страх", "херинг", "муд"},
            {"град", "берг", "цин", "дор", "стан", "ленд", "пуль", "тон", "вилль", "ока"}
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
        Sleep(100);
        int n2 = Randomize::GetRand(0,9) ; //Вторая часть города  Доделать рандом
        Sleep(100);
        int n3 = Randomize::GetRand(0,9) ; //Третья часть города
        Sleep(100);
        this->name = CityName[0][n1] + CityName[1][n2] + CityName[2][n3]; // <- Получение название города
         TypeCity test = static_cast<TypeCity>(Randomize::GetRand(0,7));  // Рандом богатости города.
         this->type = test;
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
        void EnterTheCity()
        {

        cout<< "Вы прибываете в " << this->name << " \n";
            switch (this->type)
            {
                case 0:
                    {
                        cout << "Слегка терясь в оживленных улицах,  вы выходите на главную площадь этого прекрасного города. \n";
                        cout << "Дороги в этом городе были облагороженны вырезанным вручную камнем, который служил гарниром изысканным цветам богатых оттенков, стоявших в расписных горшках у двухэтажных дворцов, что прямо по улице создавали ряды, словно грядки на картине модерниста. \n";
                        cout << "Вы не смогли не оценить ухоженности и благосостояния людей, которые, как бы намекали вам, что вы не из тех, кому дозволено отдыхать здесь\n";
                        cout << "Однако, несмотря на факты вашей неуместности," << this->name << " принимает вас и дает возможность посетить лучшие заведения этой земли";
                        break;
                    }
                case 1:
                    {
                        cout << "Этот город находится, возможно, на пике своего развития, въехав в него, вы понимаете, что вам следует остаться хотя бы на минуту дольше, чем запланированно \n";
                        cout << "Оказавшись на одном из мостов " << this->name << "вам открывается вид плотного траффика улиц, уставших лиц рабочих и занятых дам, которые будто специально настолько фальшиво изображают работу \n";
                        cout << "С каждой секундой становится яснее - городу с несломимой экономикой, армией и мудрым правителем вы не нужны, если не сможете купить здесь что-либо.";
                        cout << "Почувствовав, что вы стоите на мосту уже лишний час, вы жалеете, что выбрали не тот жизненный путь";
                    }
                case 2:
                {
                    cout << "Неуспели вы въехать в "<< this->name <<", как встали в огромную очередь из других повозок купцов, которые приезжают сюда \n";
                    cout << "Между каретами редко мельтешат краснолицие рабочие, невольно становившиеся целью ругательств кучеров \n";
                    cout << "Вскоре вы останавливаетесь в центре города - Кучи строительных материалов, потных лиц в перемешку с крупными бочками заполоняли полудостроенные дома \n";
                    cout << "Очевидно, "<<this->name <<" вскоре будет цвести и пахнуть, а пока он пыхтит и суетится - идеальное место для капиталовложения \n";
                }
                case 3:
                    {
                        cout << "Ничего особенного, "<< this->name << " - самый обкновенный город из самых обычных \n";
                        cout << "Здесь нет суеты, как в крупных городах, люди живут спокойной, честной жизнью, женщины прядут, а мужики напивыаются в кабаке \n";
                        cout << "В основном, в этом городе преобладают рабочие - улицы не чистые, но и не грязные, стекла слегка желтоваты, а некоторые цветы вянут из-за плохой хозяйки \n";
                        cout << "Вас обдал жар обычности, как бы призывающий к тому, что ваше место здесь ";
                    }
                case 4:
                {
                    cout << " Оживленные улицы "<< this->name << "остались будто в прошлом - когда то по широким дорогам этого города шли непробойные вереницы торговцев со всего мира" <<  " \n" ;
                    cout << "Одна эпидемия, другой неверный шаг правителя, третий - разбой посреди улицы и "<<this->name<<" стоит забыть о процветающем будущем"<<"\n";
                    cout << "Люди уезжают из города, предприятия закрываются, а неудачные предпринематели - банкротятся. Не стоит здесь искать выгодных предложений \n";
                    cout << "Случайный прохожий задел вас плечом, будто насильно вытолкнув вас из фантазий, намекая, что надо бежать из этого города, ни на секунду не сомневавшись \n";
                }
                case 5:
                {
                    cout << "Вас встретили у ворот, "<< this->name << " старые солдаты, которым уже была положена счастливая пенсия в порядочном городе \n";
                    cout << " Однако, им сейчас приходится охранять полуразрушенные стены старого замка, который не отпускает лишних рук \n";
                    cout << " Город борется за существование, прилавки редких купцов полупусты, а некоторые окна заколочены. \n";
                    cout << " Вас резко пронзил запах дохлой крысы - обед местного кошачьего населения, в перспективе становившееся людской платой за существование. \n";
                }
                case 6:
                {
                    cout << "Сперва вы подумали, что попали не туда куда вам нужно, однако люди, хватавшиеся за последние нити существования, своим " << this->name <<"им акцентом переубедил вас \n";
                    cout << "Бывшие дома господ находятся в печальном состоянии - притоны и редкие торговцы заполонили их, будто крысы на палубе тонущего корабля \n";
                    cout << "В разбитом городском колодце вы видите что-то похожее на скелет человека и мешочек с чем-то блестящим, потрогав карманы, вы решили держать руки в них напротяжении всего пребывания в городе \n";
                    cout << "Тем неменее суть вашего пребывания остается неизменной";
                }
                case 7:
                {
                    cout << "Перешагивая через трупы жителей " << this->name << "вы не совсем понимаете цель своего визита.  \n";
                    cout << "Недавний рейд порешал почти все живое, раненые и скорбящие перебрались в редкие полуразрушенные здания, не преданные огню. \n";
                    cout << "Возможно, стоит проверить эти домики на наличие выгоды. \n";
                }
            } // Истории городов
            cout << "Вы решаете отправиться.. \n";
            int j = 0;
            // inc[0] - Таверна, inc[1] - Рынок, inc[2] - Лагерь наемников,
            // inc[3] - Башня мага, inc[4] - Магический колодец , inc[5] - Городская площадь,
            // inc[6] - Торговец побрякушками, inc[7] - Шатер предсказательницы.
            for(int i = 0; i<7; i++)
            {
                switch (i)
                {
                   case 0:
                       {
                           if (this->inc[i] == true) {
                               Tavern tavern;
                               Enterprise *pEnterprise;
                               pEnterprise = &tavern;
                               enterprises.push_back(*pEnterprise);
                           }
                           break;
                       }
                    case 1:
                    {
                        if (this->inc[i] == true) {
                            Marketplace marketplace;
                            Enterprise *pEnterprise;
                            pEnterprise = &marketplace;
                            enterprises.push_back(*pEnterprise);
                        }
                        break;
                    }
                    case 2:
                    {
                        if (this->inc[i] == true){
                            Mercenary mercenary;
                            Enterprise *pEnterprise;
                            pEnterprise = &mercenary;
                            enterprises.push_back(*pEnterprise);
                        }
                        break;
                    }
                    case 3:
                    {
                        if (this->inc[i] == true){
                            MagicTower magicTower;
                            Enterprise *pEnterprise;
                            pEnterprise = &magicTower;
                            enterprises.push_back(*pEnterprise);
                        }
                    }
                    case 4:
                    {
                        if (this->inc[i] == true)
                        {
                            MagicWell magicWell;
                            Enterprise *pEnterprise;
                            pEnterprise = &magicWell;
                            enterprises.push_back(*pEnterprise);
                        }
                        break;
                    }
                    case 5:{
                        if (this->inc[i] == true)
                        {
                            KallTraider kallTraider;
                            Enterprise *pEnterprise;
                            pEnterprise = &kallTraider;
                            enterprises.push_back(*pEnterprise);
                        }

                    }
                    case 6:
                    {
                        if (this->inc[i] == true)
                        {
                            CityHall cityHall;
                            Enterprise *pEnterprise;
                            pEnterprise = &cityHall;
                            enterprises.push_back(*pEnterprise);
                        }
                       break;
                    }
                    case 7:
                    {
                        if (this->inc[i] == true)
                        {
                            Predict predict;
                            Enterprise *pEnterprise;
                            pEnterprise = &predict;
                            enterprises.push_back(*pEnterprise);
                        }
                        break;
                    }
                }
            }
            cin >> j;

        }
        int GetType()
        {
            return this->type;
        };

        void Show()
        {
            cout << " Тип города: " << this->type ;
            cout  << " Имя города: " <<  this->name << "\n";
            for (int i = 0; i<7; i++)
                cout  << " Предприятие номер " << i << "есть(1) или нет(0) : " << this->inc[i] << "\n";

        };

    }; // <- Класс города( Тут всё про город )



class Dungeon {
private:
    string name; // Название данжа
    int type; // Тип данжа(См ниже)
     list<int> shagi; // <- Последовательность ходов в данже
    int chdun[20] = {1,1,1,1,1,1,1,1,1,2,2,2,2,2,3,3,3,4,4,5}; // <- Возможность выпадения данжа
    // 1 - Gaybar (легко),
    // 2 - Leatherclub (средне),
    // 3 - Gym(Сложно),
    // 4 - MPT(Очень сложно),
    // 5 - Vangeon(Боссфайт).
public:
    const   int ChanceDungeon[30] =  {0,0,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4}; // Шанс выпадения типа комнаты(см ниже).
    const string DungeonName [3][10] = {
            {"Побитый  ", "Зловещий ", "Скверный ", "Забытый ", "Замшелый ", "Мрачный ", "Чудовищный ", "Величавый ", "Заброшенный ", "Богом забытый "},
            {"gym ", "dungeon ", "техникум имени ", "leatherroom ", "gay bar ", "притон ", "склеп ", "погост ", "некрополь ", "bondage gay web-site "},
            {"тёмного cum'a", "даркохльма", "районного прокурора", "фистинг клаба", "fucking'х slaves", "horny dicks", "брошенных jabhronies", "унылых гачи-треков", "ВО РЭУ им. Г.В.Плеханова", "of latex gloves"}};

   Dungeon()
    {
        int n1 = Randomize::GetRand(0,9) ; //Первая часть названия данжа
        int n2 = Randomize::GetRand(0,9) ; //Вторая часть названия данжа
        int n3 = Randomize::GetRand(0,9) ; //Третья часть названия данжа
        this->name = DungeonName[0][n1] + DungeonName[1][n2] + DungeonName[2][n3]; // <- Получение название города
        this->type = chdun[Randomize::GetRand(0,19)]; // <- Метод выдачи данжу сложности(см выше)
        switch (this->type)
        {
            // 1 - Gaybar (легко),
            // 2 - Leatherclub (средне),
            // 3 - Gym(Сложно),
            // 4 - MPT(Очень сложно),
            // 5 - Vangeon(Боссфайт).
            // Задание последовательности и длительности прохождения данжа
            // Маркировка проходов.
            // 9 - Пустой проход. (Средний шанс)
            // 0 - Выход на улицу. (Маленький шанс)
            // 1 - Темная комната. (Маленький шанс)
            // После темной комнаты обязательно спавнится одна из следующих комнат!!!
            // 10 - Темная комната -> пустая комната. (Высокий шанс).
            // 11 -  Темная комната -> комната с ловушкой. (Средний шанс).
            // 12 -  Темная комната -> комната со средней наградой. (Средний шанс).
            // 13 -  Темная комната -> комната с  большой наградой. (маленький шанс).
            // 14 -  Темная комната -> комната со смертносной ловушкой. (очень маленький шанс).
            // 2 - Ловушка (маленький шанс) (Потеря одного из артефактов(средний шанс) ИЛИ потеря части юнитов (средний шанс) ИЛИ смерть гг(очень маленький шанс))
            // 3 - Вражеские юниты (средний шанс) Внимание! Градация идет от уровня данжа. (Слабые (Маленький шанс), Средние - (Высокий шанс), Сложые (маленький шанс).
            // 4 - Сундук (низкий шанс) (Маленькая награда (Высокий шанс), Средняя награда (маленький шанс), Большая награда (очень маленький шанс))
            // 5 - Босс данжа (СМ Поле Type).
            case 1:
            {
                int lengthshag = Randomize::GetRand(3,5);
                int Droomchance[30] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 11, 11, 12, 12, 11, 11 };
                bool Chance [5][10] = {
                        {true, false, false, false, false, false, false, false, false, false}, /*  Шанс Выхода на улицу */
                        {true, false, false, false, false, false, false, false, false, false}, /*  Шанс Тёмной комнаты */
                        {true, true, true, true, false, false, false, false, false, false}, /* Шанс ловушки */
                        {true, true, true, true, true, true, false, false, false, false}, /*  Шанс врагов */
                        {true, true, true, false, false, false, false, false, false, false} /* Шанс сундук */
                         };
                SetChances(lengthshag, Chance, Droomchance);
                break;


            }
            case 2:
            {
                int lengthshag = Randomize::GetRand(4,8);
                int Droomchance[30] = { 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 13, 13, 14 };
                bool Chance [5][10] = {
                        {true, false, false, false, false, false, false, false, false, false}, /*  Шанс Выхода на улицу */
                        {true, true, true, false, false, false, false, false, false, false}, /*  Шанс Тёмной комнаты */
                        {true, true, true, true, true, true, false, false, false, false}, /* Шанс ловушки */
                        {true, true, true, true, true, true, true, false, false, false}, /*  Шанс врагов */
                        {true, true, true, true, false, false, false, false, false, false} /* Шанс сундук */
                };
                SetChances(lengthshag, Chance, Droomchance);
                break;
            }
            case 3:
            {
                int lengthshag = Randomize::GetRand(6,10);
                int Droomchance[30] = { 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 13, 13, 13, 14, 14 };
                bool Chance [5][10] = {
                        {true, false, false, false, false, false, false, false, false, false}, /*  Шанс Выхода на улицу */
                        {true, true, true, true, true, false, false, false, false, false}, /*  Шанс Тёмной комнаты */
                        {true, true, true, true, true, true, false, false, false, false}, /* Шанс ловушки */
                        {true, true, true, true, true, true, true, true, true, false}, /*  Шанс врагов */
                        {true, true, true, true, true, true, true, true, false, false} /* Шанс сундук */
                };
                SetChances(lengthshag, Chance, Droomchance);
                break;

            }
                 case 4:
                 {
                     int lengthshag = Randomize::GetRand(10,13);
                     int Droomchance[30] = { 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14 };
                     bool Chance [5][10] = {
                             {true, false, false, false, false, false, false, false, false, false}, /*  Шанс Выхода на улицу */
                        {true, true, true, true, true, true, true, true, false, false}, /*  Шанс Тёмной комнаты */
                        {true, true, true, true, true, true, true, true, true, false}, /* Шанс ловушки */
                        {true, true, true, true, true, true, true, true, true, false}, /*  Шанс врагов */
                        {true, true, true, true, true, true, true, true, true, false} /* Шанс сундук */
                };
                SetChances(lengthshag, Chance, Droomchance);
                     break;

                 }
            case 5:
            {
               // TODO Доделать Босс-данж
            }
        }

    };
    void SetChances(int lengthshag, bool Chance[5][10], int Droomchance[30]) // Метод, определяющий тип и порядок комнат в данжоне.
    {
        for (int i = 0; i<lengthshag-1; i++) // Для всей длины листа(данжона) создается цикл
        {
            int j = ChanceDungeon[Randomize::GetRand(0,30)]; // Определение комнаты

            bool ch = Chance[j][Randomize::GetRand(0,9)];    // Определение выпадание непустой комнаты


            if (ch == true)
                if (j == 1) // Если выпала темная комната
                {
                    this->shagi.push_back(Droomchance[Randomize::GetRand(0, 29)]); // Запускаем рандом темной комнаты

                }
                else
                    this->shagi.push_back(j); // Иначе даем в лист обычную комнату(не пустую)
            else
                this->shagi.push_back(9); // Пустая комната выпала
        }
        this->shagi.push_back(5); // Выдача босса данжа в конец.
    }
    void Show()
    {
        cout << "Имя данжа :" << this->name << "\n";
        cout << "Тип данжа:" << this->type << "\n";
        int i = 0;
        for (int n:this->shagi)
            cout << "Шаг номер " << i++ << ": " << n << "\n";
    }




}; // <- Класс Данжена( Тут всё про данж ).
class Outside {
private:
    int type;
    string name;
}; // <- Класс Аутсайда( Тут всё про пересеченную местность ).


#endif //UNTITLED3_LOCATIONS_H
