//
// Created by user on 12.03.2021.
//

#ifndef MAIN_CPP_BATTLE_H
#define MAIN_CPP_BATTLE_H


#include "Hero.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "Spells.h"

class Battle {
public:
    Battle(){};
    Hero *Enemy = new Hero(1);
    void StartBattle(Hero hero) {
        system("cls");
        ShowArmy(hero, *Enemy);
        Sleep(500);
        while (true) {
            int EnemysArmiesDead = 0;
            int HerosArmiesDead = 0;
            for (int i = 0; i < 10; i++) {
                if (hero.army[i].GetName() == "")
                    HerosArmiesDead++;
                if (Enemy->army[i].GetName() == "")
                    EnemysArmiesDead++;
            }
            if (EnemysArmiesDead == 10) {
                cout << "Вы выиграли!!!";
                hero.Win();
                break;
            }
            if (HerosArmiesDead == 10) {
                cout << "Вы проиграли!!!";
                hero.Lose();
                break;
            }
            bool turn = true;
            if (Randomize::GetRand(0, 1) == 0) turn = false;
            if (turn == true) {
                cout << "Ваш ход\n";
                for (int i = 0; i < 10; i++) {
                    propusk:
                    if (hero.army[i].GetName() == "") continue;
                    if (!hero.army[i].Buffs.empty()) {
                        for (Spells a: hero.army[i].Buffs) {
                            if (a.GetSpell()[0] == "Blind") {
                                cout << "Армия  " << i + 1 << " ослеплена и не может двигаться. Эффект исчезнет через "
                                     << a.GetDuration() << " хода \n";
                                if (i != 9) {
                                    i++;
                                    goto propusk;
                                }
                            }
                        }
                    }
                    st:
                    cout << "Сейчас атакует армия " << i + 1
                         << "\nВведите номер армии противника, которую они будут атаковать или 11, чтобы открыть книгу заклинаний";
                    int num;
                    if (num == 11)
                    {
                        SetSpell(hero.CastSpell(), hero, Enemy);
                        goto st;
                    }
                    cin >> num;
                    if (num > 10 || num < 1 || Enemy->army[num - 1].GetName() == "") {
                        cout << "\nВведено неверное значение\n";
                        goto st;
                    }
                    Enemy->army[num].ArmyGetDamage(hero.army[i].GetDamage() * hero.army[i].GetAmount());
                }
                turn = false;
                for (Units a : hero.army) {
                    int x = 0;
                    int x1 = -1;
                    int x2 = -1;
                    int x3 = -1;
                    for (Spells b : a.Buffs) {
                        b.SetDuration(b.GetDuration() - 1);
                        if (b.GetDuration() == 0)
                            if (x1 == -1)
                                x1 = x;
                            else if (x2 == -1)
                                x2 = x;
                            else
                                x3 = x;
                        x++;

                    }
                    if (x1 != -1)
                        a.Buffs.erase(a.Buffs.cbegin() + x1);
                    if (x2 != -1)
                        a.Buffs.erase(a.Buffs.cbegin() + x2);
                    if (x3 != -1)
                        a.Buffs.erase(a.Buffs.cbegin() + x3);
                }
            }
                        else{
                            cout << "Ход противника\n";

                            for (int i = 0; i < 10; i++) {
                                propuske:
                                if (Enemy->army[i].GetName() == "") continue;
                                st1:
                                int num = Randomize::GetRand(0, 9);
                                if (!Enemy->army[i].Buffs.empty()) {
                                    for (Spells a: Enemy->army[i].Buffs) {
                                        if (a.GetSpell()[0] == "Blind") {
                                            cout << "Армия  " << i + 1
                                                 << " ослеплена и не может двигаться. Эффект исчезнет через "
                                                 << a.GetDuration() << " хода \n";
                                            if (i != 9) {
                                                i++;
                                                goto propuske;
                                            }
                                        }
                                    }
                                }
                                if (hero.army[num].GetName() == "")
                                    goto st1;
                                hero.army[i].ArmyGetDamage(Enemy->army[i].GetDamage() * Enemy->army[i].GetAmount());
                            }
                            turn = true;

                            for (Units a : Enemy->army) {
                                int x = 0;
                                int x1 = -1;
                                int x2 = -1;
                                int x3 = -1;
                                for (Spells b : a.Buffs) {
                                    b.SetDuration(b.GetDuration() - 1);
                                    if (b.GetDuration() == 0)
                                        if (x1 == -1)
                                            x1 = x;
                                        else if (x2 == -1)
                                            x2 = x;
                                        else
                                            x3 = x;
                                    x++;

                                }
                                if (x1 != -1)
                                a.Buffs.erase(a.Buffs.cbegin() + x1);
                                if (x2 != -1)
                                    a.Buffs.erase(a.Buffs.cbegin() + x2);
                                if (x3 != -1)
                                    a.Buffs.erase(a.Buffs.cbegin() + x3);



                            }
                        }
                        break;
                    }
                }


    void SetEnemy(Hero enemy){
        *Enemy = enemy;
    }
    void ShowArmy(Hero hero, Hero enemy){
        cout << "\tВы:" << setw(123) << "Ваш противник:\n";
        string name1, name2,res;
        for (int i = 0; i < 10; i++){
            if (hero.army[i].GetName() == "")
                name1 = to_string(i+1) + ") Пусто";
            else
                name1 = to_string(i + 1) + ") " + hero.army[i].GetName() + ", Урон: " + to_string(hero.army[i].GetDamage() * hero.army[i].GetAmount()) +  ", Здоровье: " +to_string( hero.army[i].GetHP() * hero.army[i].GetAmount()) +", Броня: " + to_string( hero.army[i].GetArmor());
            if (enemy.army[i].GetName() == "")
                name2 = to_string(i+1) + ") Пусто";
            else
                name2 = to_string(i + 1) + ") " + enemy.army[i].GetName() + ", Урон: " + to_string(enemy.army[i].GetDamage() * enemy.army[i].GetAmount()) +  ", Здоровье: " +to_string( enemy.army[i].GetHP() * enemy.army[i].GetAmount()) +", Броня: " + to_string( enemy.army[i].GetArmor());
            cout <<"\t"<<left << setw(100 + (size(name1)/2.85)) << name1 << right  << name2  << endl;
        }
    }
    void SetSpell(Spells a, Hero hero, Hero *enemy)
    {
        cout << "Выбрано заклинание "<< a.GetSpell()[0] << " \n";
        cout << "Выберите цель заклинания \n";
        int j;
        cin >> j;
        j--;
        if (a.GetSpell()[2] == "Damage")
        {
// TODO если успею доделатть защиту от магии
            if (a.GetSpell()[4] == "1")
            enemy->army[j].ArmyGetDamage(hero.GetMagicStrength()/10*atoi(a.GetSpell()[3].c_str()) +  atoi(a.GetSpell()[3].c_str()));
            else
                if (enemy->army.size()>atoi(a.GetSpell()[4].c_str()))
                {
                    int x = atoi(a.GetSpell()[4].c_str())-1;
                    if (j == 0)
                    {
                        while (j<x/2)
                        {
                            enemy->army[j].ArmyGetDamage(hero.GetMagicStrength()/10*atoi(a.GetSpell()[3].c_str()) +  atoi(a.GetSpell()[3].c_str()));
                            cout << "\n";                             cout << "\n";                             cout << "\n";
                            cout << "Заклинание" << a.GetSpell()[0] << " нанесло " << hero.GetMagicStrength()/10*atoi(a.GetSpell()[3].c_str()) +  atoi(a.GetSpell()[3].c_str()) << " урона.\n";
                            j++;
                        }
                    }
                    else if (j == x-1)
                    {
                        while (j>x/2)
                        {
                            enemy->army[j].ArmyGetDamage(hero.GetMagicStrength()/10*atoi(a.GetSpell()[3].c_str()) +  atoi(a.GetSpell()[3].c_str()));
                            cout << "\n";                             cout << "\n";                             cout << "\n";
                            cout << "Заклинание" << a.GetSpell()[0] << " нанесло " << hero.GetMagicStrength()/10*atoi(a.GetSpell()[3].c_str()) +  atoi(a.GetSpell()[3].c_str()) << " урона.\n";
                            j--;
                        }
                    }
                    else
                    {
                        for (int i = j-x+1; i< j+x+1; i++)
                        {
                            enemy->army[i].ArmyGetDamage(hero.GetMagicStrength()/10*atoi(a.GetSpell()[3].c_str()) +  atoi(a.GetSpell()[3].c_str()));
                        }
                        cout << "\n";                             cout << "\n";                             cout << "\n";
                        cout << "Заклинание" << a.GetSpell()[0] << " нанесло " << hero.GetMagicStrength()/10*atoi(a.GetSpell()[3].c_str()) +  atoi(a.GetSpell()[3].c_str()) << " урона.\n";
                    }
                }
                else
                {
                    for(Units b: enemy->army)
                        b.ArmyGetDamage(hero.GetMagicStrength()/10*atoi(a.GetSpell()[3].c_str()) +  atoi(a.GetSpell()[3].c_str()));
                }
            hero.SetMana(hero.GetMana()-atoi(a.GetSpell()[6].c_str()));

        }
        else
        {
            if(enemy->army[j].Buffs.size() == 3)
            {
                cout << "На отряде слишком много чар! Подождите пока они прекратят свои действия \n";
                for(Spells b:enemy->army[j].Buffs)
                    cout << " " << b.GetSpell()[0] << ". Осталось " << b.GetSpell()[4] << " хода\n";
            }
            else{
                if (a.GetSpell()[0]!="Dimensiondoor")
                    enemy->army[j].Buffs.push_back(a);
             /*   else
                    TeleportToCity();*/
            }
        }

    }


};


#endif //MAIN_CPP_BATTLE_H
