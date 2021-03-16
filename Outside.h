//
// Created by kosty on 13.03.2021.
//

#ifndef UNTITLED3_OUTSIDE_H
#define UNTITLED3_OUTSIDE_H
#include <vector>
#include "Perks.h"
#include "Randomize.h"
#include "Enterprises.h"
#include "Hero.h"
#include "Locations.h"
#include "Battle.h"

class Outside {
private:
    vector <int> path ;
public:
    constexpr const static int ver[30] = {1, 1, 1, 1, 1, 1, 1, 3, 3, 0, 0, 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 9, 9, 4, 4, 4, 4, 4, 4, 4};
    Outside()
    {
        // 0 - город (после города всегда дорога).
        // 1 - дорога (вероятность высокая)
        // 2 - засада на дороге (вероятность средняя).
        // 3 - Дорога завела вас в лес.
        // 9 - ловушка в лесу.
        // 4 - данжон.

    }
    void SetPath(Hero hero)
    {
        path.clear();
        int PathLength = Randomize::GetRand(3,15);
        int rand;
        bool end = false;
        for (int i = 0; i<PathLength; i++) {
            if (end == true)
                break;
            else if (i == PathLength - 2)
                path.push_back(1);
            else if (i == PathLength - 1)
                path.push_back(0);
            else if (i == 0) {
                path.push_back(1);
            } else {
                povtor:
               Sleep(500);
                rand = ver[Randomize::GetRand(0, 29)];
                switch (rand) {
                    case 0: {
                        if (path.size() > 1)
                            path.push_back(rand);
                        else
                            end = true;
                        break;
                    }
                    case 2: {
                        if (path[i - 1] == 1 || path[i - 1] == 2)
                            path.push_back(rand);
                        else
                            goto povtor;
                        break;
                    }
                    case 9: {
                        if (path[i - 1] == 3)
                            path.push_back(rand);
                        else
                            goto povtor;
                        break;

                    }
                    case 4: {
                        if (path[i - 1] == 3)
                            path.push_back(rand);
                        else
                            goto povtor;
                        break;
                    }
                    default: {
                        path.push_back(rand);
                        break;
                    }
                }
            }
            LeaveTheCity(hero);
        }
    }
    void LeaveDungeon(Hero hero){
        cout << "Вы сбежали из Дунгеона, повезло, повезло...\n";
        Sleep(2000);
        SetPath(hero);
    }
    void LeaveTheCity(Hero hero)
    {
        bool city = false;
        for (int i = 0; i<path.size(); i++) {
            if (city == true)
                break;
            else {
                if (i == 0)
                    cout << "Вы идёте по мощщеной дороге, вас обдувает слегка теплый ветер... ";
                else {
                    Sleep(200);
                    switch (path[i]) {
                        case 0: {
                            cout << "Дорога привела вас в Город.\n ";
                             city = true;
                            break;

                        }
                        case 1: {
                            if (path[i - 1] == 1) {
                                Sleep(500);
                                cout << "*Процесс ходьбы по дороге* \n";
                            } else {
                                Sleep(500);
                                cout << "Наконец вы находите тропинку, которая выводит вас из гущи леса прямо на дорогу посреди поля. \n";
                            }
                            break;

                        }
                        case 2: {
                            if (path[i - 1] == 2) {
                                cout << "Оказывается это было только начало, к врагу спешит подкрепление! \n";
                                Battle *battle = new Battle();
                                battle->StartBattle(hero);
                                delete battle;
                            } else {
                                cout
                                        << "Вы чувствуете, что происходит на этой дороге что-то неладное, как вдруг из-под ближайшего холма выходит отряд наемников \n";
                                cout
                                        << "Может это месть? Но за что? Скорее всего обычные Slaves решили поживиться атрибутами Dungeon master. Вы командуете занять отрядам свои позиции \n";
                                Battle *battle = new Battle();
                                battle->StartBattle(hero);
                                delete battle;
                            }
                            break;

                        }
                        case 3: {
                            if (path[i - 1] == 3) {
                                Sleep(500);
                                cout << "*Процесс пересечения леса* \n";
                            } else {
                                cout << "Вы и не заметили, как извилистая дорога завела вас в лес.. \n";
                            }
                            break;

                        }
                        case 4: {
                            if (path[i - 1] == 3) {
                                cout
                                        << "Покинув первый данж, вы натыкаетесь на второй - похоже тут проложена целая система \n";
                                cout << "Может эти заброшенные гробницы раньше были городами, кто знает? \n";
                            } else if (path[i - 1] == 3) {
                                cout
                                        << "Сквозь гущу леса вы натыкаетесь на поляну, центр которой занят каким-то огромным зданием, напоминающем гробницу \n";
                                cout
                                        << "Вы чувствуете зловещее присутствие, однако разорение такой гробницы может сулить большую выгоду \n";

                            }
                            if (path[i - 1] == 3 || path[i - 1] == 3)
                                cout << "1) Войти в Dungeon \n";
                            cout << "2) Продолжить путешествие \n";
                            int j;
                            cin >> j;
                            if (j == 2) {
                                i++;
                            } else {
                                Dungeon *Dunj = new Dungeon();
                                Dunj->EnterTheDungeon(hero);
                            }
                            break;
                        }
                    }
                }
            }
        }



        system("cls");
    }

}; // <- Класс Аутсайда( Тут всё про пересеченную местность ).



#endif //UNTITLED3_OUTSIDE_H
