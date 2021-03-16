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
#include "Boss.h"

class Battle {
public:
    Hero *Enemy = new Hero(1);
    void StartBattle(Hero hero) {
        system("cls");
        SetEnemy();
        ShowArmy(hero, *Enemy);
        Sleep(500);
        bool turn = true;
        if (Randomize::GetRand(0, 1) == 0) turn = false;
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
                cout << "Вы выиграли!!!\n";
                hero.Win();
                break;
            }
            if (HerosArmiesDead == 10) {
                cout << "Вы проиграли...\n";
                hero.Lose();
                break;
            }
            if (turn == true) {
                cout << "Ваш ход\n";
                for (int i = 0; i < 10; i++) {
                    propusk:
                    if (hero.army[i].GetName() == "") continue;
                    if (!hero.army[i].Buffs.empty()) {
                        for (Spells a: hero.army[i].Buffs) {
                            if (a.GetName() == "Blind") {
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
                                        if (a.GetName() == "Blind") {
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
    void StartBossFight(Hero hero, int Hardness){
        Boss *boss = new Boss(Hardness);
        IntroBoss(*boss);
        ShowBossFight(hero,*boss);
        bool turn = true;
        if (Randomize::GetRand(0, 1) == 0) turn = false;
        while (true){
            int HerosArmiesDead = 0;
            for (int i = 0; i < 10; i++)
                if (hero.army[i].GetName() == "") HerosArmiesDead++;
            if (HerosArmiesDead == 10) {
                cout << "Босс вас переиграл и уничтожил...\n";
                hero.Lose();
                break;
            }
            if (boss->GetHP() <= 0){
                cout << "Вы выиграли Босса!!!\n";
                hero.Win();
                break;
            }
            if (turn == true){
                cout << "Ваш ход\n";
                for (int i = 0; i < 10; i++){
                    cout << "Сейчас атакует армия "<<i+1 << endl;
                    Sleep(500);
                    int damage = hero.army[i].GetDamage()*hero.army[i].GetAmount();
                    boss->BossGetDamage(damage);
                    damage - boss->GetArmor() <= 0 ? damage = 0: damage -= boss->GetArmor();
                    cout << "Босс получил "<< damage << " урона!\n";
                    ShowBossFight(hero,*boss);
                }
                turn = false;
            }
            else{
                cout << "Ход противника\n";
                st:
                int num = Randomize::GetRand(0,9);
                if (hero.army[num].GetName() == "") goto st;
                hero.army[num].ArmyGetDamage(boss->GetDamage());
                ShowBossFight(hero,*boss);
                turn = true;
            }
        }
    }


    void SetEnemy(){
        string uns[18] = {"Лучник","Воин","Волшебник","Снайпер","Задира","Колдун","Копейщик","Заклинатель","Чернокнижник","Лучница","Чародей","Убийца","Энт-защитник","Энт-чародей","Энт-разведчик","Пожиратель душ","Чернокнижник","Люцифер"};
        for (int i = 0; i < 10; i++){
            Enemy->army[i].BuyUnits(uns[Randomize::GetRand(0,17)]);
            Enemy->army[i].SetAmount(Randomize::GetRand(0,4));
        }
    }
    void ShowArmy(Hero hero, Hero enemy){
        cout << "\tВы:" << setw(123) << "Ваш противник:\n";
        string name1, name2;
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
    void ShowBossFight(Hero hero, Boss boss){
        Sleep(1000);
        system("cls");
        cout << "\tВы:" << setw(123) << boss.GetName();
        string name1, name2;
        for (int i = 0; i < 10; i++){
            if (hero.army[i].GetName() == "")
                name1 = to_string(i+1) + ") Пусто";
            else
                name1 = to_string(i + 1) + ") " + hero.army[i].GetName() + ", Урон: " + to_string(hero.army[i].GetDamage() * hero.army[i].GetAmount()) +  ", Здоровье: " +to_string( hero.army[i].GetHP() * hero.army[i].GetAmount()) +", Броня: " + to_string( hero.army[i].GetArmor());
            name2 = "Урон: " + to_string(boss.GetDamage()) + " Здоровье: " + to_string(boss.GetHP()) + " Броня " + to_string(boss.GetArmor());
            cout <<"\t"<<left << setw(100 + (size(name1)/2.85)) << name1 << right  << name2  << endl;//вместо name2 строчки рисунка босса
        }
    }
    void IntroBoss(Boss boss){
        system("cls");
        //cout << "\n\n\t\t"<<boss.GetPicture(); Пока хз как реализовать картинку
        cout << "\n\n\t\tХа-ха, я величайшее существо этого мира!\n\n\t\tМое имя - "<<boss.GetName()<<"\n\n\t\tЯ тебя уничтожу *MUDA MUDA MUDA MUDA MUDA MUDA MUDA MUDA*\n";
        Sleep(5000);
    }

    void SetSpell(Spells a, Hero hero, Hero *enemy)
    {
        cout << "Выбрано заклинание "<< a.GetName() << " \n";
        cout << "Выберите цель заклинания \n";
        int j;
        cin >> j;
        j--;
        //Name, Type, to_string(Damage), to_string(Distance), to_string(Duration), to_string(Level), to_string(MCost), to_string(GCost)
        if (a.GetType() == "Damage")
        {
// TODO если успею доделатть защиту от магии
            if (a.GetDistance() == 1)
            enemy->army[j].ArmyGetDamage(hero.GetMagicStrength()/10*a.GetDamage() +  a.GetDamage());
            else
                if (enemy->army.size()>a.GetDistance())
                {
                    int x = a.GetDistance()-1;
                    if (j == 0)
                    {
                        while (j<x/2)
                        {
                            enemy->army[j].ArmyGetDamage(hero.GetMagicStrength()/10*a.GetDamage() +  a.GetDamage());
                            cout << "\n";                             cout << "\n";                             cout << "\n";
                            cout << "Заклинание" << a.GetName() << " нанесло " << hero.GetMagicStrength()/10*a.GetDamage() +  a.GetDamage()<< " урона.\n";
                            j++;
                        }
                    }
                    else if (j == x-1)
                    {
                        while (j>x/2)
                        {
                            enemy->army[j].ArmyGetDamage(hero.GetMagicStrength()/10*a.GetDamage() +  a.GetDamage());
                            cout << "\n";                             cout << "\n";                             cout << "\n";
                            cout << "Заклинание" << a.GetName() << " нанесло " << hero.GetMagicStrength()/10*a.GetDamage() +  a.GetDamage() << " урона.\n";
                            j--;
                        }
                    }
                    else
                    {
                        for (int i = j-x+1; i< j+x+1; i++)
                        {
                            enemy->army[i].ArmyGetDamage(hero.GetMagicStrength()/10*a.GetDamage() +  a.GetDamage());
                        }
                        cout << "\n";                             cout << "\n";                             cout << "\n";
                        cout << "Заклинание" << a.GetName() << " нанесло " << hero.GetMagicStrength()/10*a.GetDamage() +  a.GetDamage() << " урона.\n";
                    }
                }
                else
                {
                    for(Units b: enemy->army)
                        b.ArmyGetDamage(hero.GetMagicStrength()/10*a.GetDamage() +  a.GetDamage());
                }
            hero.SetMana(hero.GetMana()-a.GetMCost());

        }
        else
        {
            if(enemy->army[j].Buffs.size() == 3)
            {
                cout << "На отряде слишком много чар! Подождите пока они прекратят свои действия \n";
                for(Spells b:enemy->army[j].Buffs)
                    cout << " " << b.GetName() << ". Осталось " << b.GetDuration() << " хода\n";
            }
            else{
                if (a.GetName()!="Dimensiondoor")
                    enemy->army[j].Buffs.push_back(a);
            //else
                    //Outside::LeaveDungeon(hero);
            }
        }

    }


};


#endif //MAIN_CPP_BATTLE_H
