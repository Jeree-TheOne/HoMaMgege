//
// Created by JerEe^ on 01.03.2021.
//

#ifndef UNTITLED3_HERO_H
#define UNTITLED3_HERO_H
#include <windows.h>
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <array>
#include "Perks.h"
#include "Equipment.h"
#include "Spells.h"
#include "Randomize.h"
using namespace std;

enum Types{
    Archer = 1,
    Warrior,
    Mag
};


class Hero {
private:
    string Type;
    int Damage;
    int HP;
    int Armor;
    int Intellect;
    int MagicStrength;
    int Gold = 2500;
    int Xp = 0;
    int Lvl = 1;
public: //todo: Изменить массивы на векторы
    int a;
    array<Equipment, 10> Equiped;// Слоты инвенторя Helmet, Amulet, ChestArmor, LeftHand, RightHand, Ring, Nogi, Pet, Access
    vector<Perks> perks; //Перки изначально дается 2 рандомных, не повторяются
    //string SpellBook[10]; Книжка спеллов, хз какой у нее размер, мб можно листом сделать
    vector<Equipment> Inventory;
    Hero(int type)
    {
        switch (type) {
            case 1: //По номеру типа
                Type = "Лучник";
                Damage = 7 + Randomize::GetRand(0,3);
                HP = 5 + Randomize::GetRand(0,2);
                Armor = 1 + Randomize::GetRand(0,2);
                Intellect = 1 + Randomize::GetRand(0,1);
                MagicStrength = 1 + Randomize::GetRand(0,1);
                perks.push_back(Perks());
                st:
                perks.push_back(Perks());
                if (perks[0].Name == perks[1].Name) {
                    perks.pop_back();
                    goto st;
                }
                break;
            case 2: //По номеру типа
                Type = "Воин";
                Damage = 5 + Randomize::GetRand(0,3);
                HP = 6 + Randomize::GetRand(0,4);
                Armor = 4 + Randomize::GetRand(0,3);
                Intellect = 1 + Randomize::GetRand(0,1);
                MagicStrength = 1 + Randomize::GetRand(0,1);
                perks.push_back(Perks());
            st1:
                perks.push_back(Perks());
                if (perks[0].Name == perks[1].Name) {
                    perks.pop_back();
                    goto st1;
                }
                break;
            case 3: //По номеру типа
                Type = "Волшебник";
                Damage = 3 + Randomize::GetRand(0,2);
                HP = 2 + Randomize::GetRand(0,2);
                Armor = 0 + Randomize::GetRand(0,1);
                Intellect = 5 + Randomize::GetRand(0,3);
                MagicStrength = 5 + Randomize::GetRand(0,3);
                perks.push_back(Perks());
            st2:
                perks.push_back(Perks());
                if (perks[0].Name == perks[1].Name) {
                    perks.pop_back();
                    goto st2;
                }
                break;
        }
    }

    void ShowStats(){
        cout << "Статы: \n";
        cout << "Урон: " << Damage << endl;
        cout << "Здоровье: " << HP << endl;
        cout << "Броня: " << Armor << endl;
        cout << "Интеллект: " << Intellect << endl;
        cout << "Магическая сила: " << MagicStrength << endl;
        cout << "Золото: " << Gold << endl;
        cout << "Опыта до следующего уровня: " << Lvl*10 - Xp << endl;
    }

    void GetXp(int xp){
        Xp += xp;
        if (Xp >= Lvl*10){
            Xp -= Lvl*10;
            ++Lvl;
            if (Type == "Лучник"){
                Damage += 2 + Randomize::GetRand(0,2);
                HP += 1 + Randomize::GetRand(0,1);
                Armor += 1 + Randomize::GetRand(0,1);
                Intellect +=  Randomize::GetRand(0,1);
                MagicStrength +=  Randomize::GetRand(0,1);
            } else if (Type == "Воин"){
                Damage += 2 + Randomize::GetRand(0,1);
                HP += 2 + Randomize::GetRand(0,2);
                Armor += 2 + Randomize::GetRand(0,2);
                Intellect +=  Randomize::GetRand(0,1);
                MagicStrength +=  Randomize::GetRand(0,1);
            } else if (Type == "Волшебник"){
                Damage += 1 + Randomize::GetRand(0,1);
                HP += 1 + Randomize::GetRand(0,1);
                Armor += Randomize::GetRand(0,1);
                Intellect += 2 + Randomize::GetRand(0,2);
                MagicStrength += 2 + Randomize::GetRand(0,2);
            }
            cout << "Вы получили новый уровень!! Текущий уровень - " << Lvl;
            // Todo: Реализовать выпадения 2-3 перков
        }
        return;
    }

    void AddToInventory(Equipment item){
        Inventory.push_back(item);
        system("cls");
        cout << "\nПредмет добавлен в инвентарь\n\n";
    }

    void Equip(Equipment item){
        if (item.GetType() == "Шлем"){
            if (Equiped[0].GetName() != "")
                Inventory.push_back(Equiped[0]);
            Equiped.at(0) = item;
        }
        else if (item.GetType() == "Амулет"){
            if (Equiped[1].GetName() != "")
                Inventory.push_back(Equiped[1]);
            Equiped.at(1) = item;
        }
        else if (item.GetType() == "Нагрудник"){
            if (Equiped[2].GetName() != "")
                Inventory.push_back(Equiped[2]);
            Equiped.at(2) = item;
        }
        else if (item.GetType() == "Левая рука"){
            if (Equiped[3].GetName() != "")
                Inventory.push_back(Equiped[3]);
            Equiped.at(3) = item;
        }
        else if (item.GetType() == "Правая рука"){
            if (Equiped[4].GetName() != "")
                Inventory.push_back(Equiped[4]);
            Equiped.at(4) = item;
        }
        else if (item.GetType() == "Кольцо"){
            if (Equiped[5].GetName() != "")
                Inventory.push_back(Equiped[5]);
            Equiped.at(5) = item;
        }
        else if (item.GetType() == "Ноги"){
            if (Equiped[6].GetName() != "")
                Inventory.push_back(Equiped[6]);
            Equiped.at(6) = item;
        }
        else if (item.GetType() == "Питомец"){
            if (Equiped[7].GetName() != "")
                Inventory.push_back(Equiped[7]);
            Equiped.at(7) = item;
        }
        else if (item.GetType() == "Аксессуар") {
            cout << "Какой слот акксессуара поменять 1 или 2? \n";
            int num;
            cin >> num;
            if (num == 1){
                if (Equiped[8].GetName() != "")
                    Inventory.push_back(Equiped[8]);
                Equiped.at(8) = item;
            }
            else{
                if (Equiped[9].GetName() != "")
                    Inventory.push_back(Equiped[9]);
                Equiped.at(9) = item;
            }
        }
        system("cls");
        int* nums = new int[6];
        nums = FormatForBonusStats(item.GetStats());
        Damage += nums[0];
        HP += nums[1];
        Armor += nums[2];
        Intellect += nums[3];
        MagicStrength += nums[4];
        cout << "\nПредмет надет успешно\n\n";
    }


    void MoveFromInventoryToEquiped(int index){
        Equip(Inventory[index - 1]);
        Inventory.erase(Inventory.begin() + index - 1);
    }

    void MoveFromEquipedToInventory(int index){
        if (Equiped[index - 1].GetName() == ""){
            cout << "\nВ данном слоте нет никакой шмотки\n";
            return;
        }
        int* nums = new int[6];
        nums = FormatForBonusStats(Equiped[index - 1].GetStats());
        Damage -= nums[0];
        HP -= nums[1];
        Armor -= nums[2];
        Intellect -= nums[3];
        MagicStrength -= nums[4];
        Inventory.push_back(Equiped[index - 1]);// Если шмотки нет, то не должно быть возможности ее заменить иначе пздц в инвентаре будет
        Equiped[index - 1] =  Equipment();
        system("cls");
        cout << "\nПредмет перемещен в инвентарь\n";
    }

    void ShowInventory(){
        for (int i = 0; i < size(Inventory); i++) {
            cout << i + 1 << ") " << Inventory[i].GetName() << endl;
        }
        if (size(Inventory) == 0){
            system("cls");
            cout <<"\nИнвентарь пуст\n";
            return;
        }
        st:
        cout << "\nВыберите действие: \n1) Выбрать предмет\n2) Выйти из инвентаря\n";
        int ch;
        cin >> ch;
        switch (ch) {
            case 1:
                st2:
                cout << "\nВведите номер предмета: ";
                int index;
                cin >> index;
                if (index < 1 || index > size(Inventory)) {
                    cout << "\nПредмета с таким номером у вас нет\n";
                    goto st2;
                }
                st3:
                cout << "\nПредмет: " << Inventory[index - 1].GetName();
                cout << "\nСтаты: "<< endl;
                cout << Format::DeFormat(Inventory[index - 1].GetStats()) << endl;
                cout << "Что вы хотите сделать с этим предметом?\n1) Надеть\n2) Удалить\n3) Выйти из инвентаря\n";
                cin >> ch;
                switch (ch) {
                    case 1:
                        MoveFromInventoryToEquiped(index);
                        break;
                    case 2:
                        Inventory.erase(Inventory.begin() + index - 1);
                        break;
                    case 3:
                        system("cls");
                        return;
                    default:
                        cout << "\nВы ввели неправильное значение\n";
                        goto st3;
                }
                break;
            case 2:
                system("cls");
                return;
            default:
                cout << "\nВы ввели неправильное значение\n";
                goto st;
        }

    }

    void ShowEquiped(){
        for(int i = 0; i < size(Equiped); i++ ) {
            if (Equiped[i].GetName() != "")
                cout << i + 1 << ": " << Equiped[i].GetType() << " - " << Equiped[i].GetName() << endl;
            else
                cout << i + 1 << ": Пусто\n";
        }
        st:
        cout << "\nВыберите действие: \n1) Выбрать предмет\n2) Выйти из экипировки\n";
        int ch;
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nВведите номер предмета: \n";
                int index;
                cin >> index;
                if (index < 1 || index > 10) {
                    cout << "\nНеверно введено значение\n";
                    goto st;
                }
                else if (Equiped[index - 1].GetName() == ""){
                    cout << "Данный слот пустой\n";
                    goto st;
                }
                st3:
                cout << "\nПредмет: " << Equiped[index - 1].GetName();
                cout << "\nСтаты: "<< endl;
                cout << Format::DeFormat(Equiped[index - 1].GetStats()) << endl;
                cout << "Что вы хотите сделать с этим предметом?\n1) Поместить в инвентарь\n2) Выйти из экипировки\n";
                cin >> ch;
                switch (ch) {
                    case 1:
                        MoveFromEquipedToInventory(index);
                        break;
                    case 2:
                        system("cls");
                        return;
                    default:
                        cout << "\nВы ввели неправильное значение\n";
                        goto st3;
                }
                break;
            case 2:
                system("cls");
                break;
            default:
                cout << "\nВы ввели неправильное значение\n";
                goto st;
        }
    }

};


#endif //UNTITLED3_HERO_H
