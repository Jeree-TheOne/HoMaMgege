//
// Created by JerEe^ on 01.03.2021.
//

#ifndef UNTITLED3_HERO_H
#define UNTITLED3_HERO_H
#include <windows.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <list>
#include <vector>
#include <array>
#include "Perks.h"
#include "Equipment.h"
#include "Randomize.h"
#include "Units.h"
#include "Spells.h"
using namespace std;

class Hero {
private:
    string Type;
    int Damage;
    int HP;
    int Armor;
    int Intellect;
    int MagicStrength;
    int MAXmana = 10;
    int Mana = MAXmana;
    int Gold = 2500;
    int Xp = 0;
    int Lvl = 1;
public:
    array<Equipment, 10> Equiped;// Слоты инвенторя Helmet, Amulet, ChestArmor, LeftHand, RightHand, Ring, Nogi, Pet, Access
    array<Perks, 4> perks; //Перки изначально дается 2 рандомных, не повторяются
    array<Units, 10> army;
    vector<Equipment> Inventory;
    vector<Spells> MagicBook;
    Hero(int type)
    {
        army[0].BuyUnits("Лучник");
        army[0].SetAmount(10);
        army[0].AddHeroStats(Damage, Armor, HP);
        army[1].BuyUnits("Воин");
        army[1].SetAmount(10);
        army[1].AddHeroStats(Damage, Armor, HP);
        Perks *perks1 = new Perks();
        perks1->NewPerk();
        perks.at(0) = *perks1;
        Perks *perks2 = new Perks();
        st:
        perks2->NewPerk();
        perks.at(1) = *perks2;
        if (perks[0].GetName() == perks[1].GetName())
             goto st;
        switch (type) {
            case 1: //По номеру типа
                Type = "Лучник";
                Damage = 7 + Randomize::GetRand(0,3);
                HP = 5 + Randomize::GetRand(0,2);
                Armor = 1 + Randomize::GetRand(0,2);
                Intellect = 1 + Randomize::GetRand(0,1);
                MagicStrength = 1 + Randomize::GetRand(0,1);
                break;
            case 2: //По номеру типа
                Type = "Воин";
                Damage = 5 + Randomize::GetRand(0,3);
                HP = 6 + Randomize::GetRand(0,4);
                Armor = 4 + Randomize::GetRand(0,3);
                Intellect = 1 + Randomize::GetRand(0,1);
                MagicStrength = 1 + Randomize::GetRand(0,1);
                break;
            case 3: //По номеру типа
                Type = "Волшебник";
                Damage = 3 + Randomize::GetRand(0,2);
                HP = 2 + Randomize::GetRand(0,2);
                Armor = 0 + Randomize::GetRand(0,1);
                Intellect = 5 + Randomize::GetRand(0,3);
                MagicStrength = 5 + Randomize::GetRand(0,3);
                break;
        }
        for (int i = 0; i < 4; i++){
            if (perks[i].GetName() != "") {
                int stat = Format::FormatForPerkBonusStats(perks[i].GetAction());
                string act ="";
                for (int j = 0; j < 2; j++){
                    if (!isdigit(perks[i].GetAction()[j]))
                        act += perks[i].GetAction()[j];
                }
                if (act == "D")
                    Damage+=stat;
                else if (act == "A")
                    Armor+=stat;
                else if ( act == "I")
                    Intellect+=stat;
                else
                    MagicStrength+=stat;
            }
        }
    }

    void GetXp(int xp){
        Xp += xp;
        if (Xp >= Lvl*10){
            Xp -= Lvl*10;
            ++Lvl;
            for (int i= 0;i < 10; i++)
                if (army[i].GetName() != "")
                    army[i].DeleteHeroStats(Damage, Armor, HP);
            for (int i = 0; i < 4; i++){
                if (perks[i].GetName() != "") {
                    int stat = Format::FormatForPerkBonusStats(perks[i].GetAction());
                    string act ="";
                    for (int j = 0; j < 2; j++){
                        if (!isdigit(perks[i].GetAction()[j]))
                            act += perks[i].GetAction()[j];
                    }
                    if (act == "D")
                        Damage-=stat;
                    else if (act == "A")
                        Armor-=stat;
                    else if ( act == "I")
                        Intellect-=stat;
                    else
                        MagicStrength-=stat;
                }
            }
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
            cout << "Вы получили новый уровень!! Текущий уровень - " << Lvl << endl;
            cout << "Навыки за новый уровень:\n\n";
            if (perks[3].GetName() == "") {
                Sleep(1000);
                Perks *perks1 = new Perks();
                perks1->NewPerk();
                if (perks1->GetName() == perks[0].GetName() || perks1->GetName() == perks[1].GetName() || perks1->GetName() == perks[2].GetName() || perks1->GetName() == perks[3].GetName())
                    cout << "1) "<<perks1->GetName() <<": улучшение\n";
                else
                    cout << "1) "<<perks1->GetName() <<": "<< Format::PerkDeFormat(perks1->GetAction());
                Sleep(1000);
                Perks *perks2 = new Perks();
                perks2->NewPerk();
                if (perks2->GetName() == perks[0].GetName() || perks2->GetName() == perks[1].GetName() || perks2->GetName() == perks[2].GetName() || perks2->GetName() == perks[3].GetName())
                    cout << "2) "<<perks2->GetName() <<": улучшение\n";
                else
                    cout << "2) "<<perks2->GetName() <<": "<< Format::PerkDeFormat(perks2->GetAction());
                st:
                cout << "Выберите навык который хотите добавить: ";
                int ch;
                cin >> ch;
                switch (ch) {
                    case 1:
                        if (perks1->GetName() == perks[0].GetName() || perks1->GetName() == perks[1].GetName() || perks1->GetName() == perks[2].GetName() || perks1->GetName() == perks[3].GetName()) {
                            for (int i = 0; i < 4; i++)
                                if (perks1->GetName() == perks[i].GetName()) {
                                    if (perks[i].GetStage() == 3) {
                                        cout << "\nНавык уже максимального уровня\n";
                                        break;
                                    }
                                    perks[i].UpgradePerk();
                                    cout << "\nНавык улучшен\n";
                                }
                            break;
                        }
                        if (perks[2].GetName() == "")
                            perks.at(2) = *perks1;
                        else
                            perks.at(3) = *perks1;
                        cout << "\nНавык "<<perks1->GetName()<< " добавлен\n";
                        break;
                    case 2:
                        if (perks2->GetName() == perks[0].GetName() || perks2->GetName() == perks[1].GetName() || perks2->GetName() == perks[2].GetName() || perks2->GetName() == perks[3].GetName()) {
                            for (int i = 0; i < 4; i++)
                                if (perks2->GetName() == perks[i].GetName()) {
                                    if (perks[i].GetStage() == 3) {
                                        cout << "\nНавык уже максимального уровня\n";
                                        break;
                                    }
                                    perks[i].UpgradePerk();
                                    cout << "\nНавык улучшен\n";
                                }
                            break;
                        }
                        if (perks[2].GetName() == "")
                            perks.at(2) = *perks2;
                        else
                            perks.at(3) = *perks2;
                        cout << "\nНавык "<<perks2->GetName()<< " добавлен\n";
                        break;
                    default:
                        cout << "Вы ввели неправильное значение\n";
                        goto st;
                }
            }
            else{
                Perks *perks1 = new Perks();
                p1:
                Sleep(1000);
                perks1->NewPerk();
                if (perks1->GetName() != perks[0].GetName() && perks1->GetName() != perks[1].GetName() && perks1->GetName() != perks[2].GetName() && perks1->GetName() != perks[3].GetName())
                    goto p1;
                Perks *perks2 = new Perks();
                p2:
                Sleep(1000);
                perks2->NewPerk();
                if (perks2->GetName() != perks[0].GetName() && perks2->GetName() != perks[1].GetName() && perks2->GetName() != perks[2].GetName() && perks2->GetName() != perks[3].GetName())
                    goto p2;
                cout << "1) "<<perks1->GetName() <<": улучшение\n";
                cout << "2) "<<perks2->GetName() <<": улучшение\n";
                st2:
                cout << "Выберите навык который хотите добавить: ";
                int ch;
                cin >> ch;
                switch (ch) {
                    case 1:
                        for (int i = 0; i < 4; i++)
                            if (perks1->GetName() == perks[i].GetName()){
                                if (perks[i].GetStage() == 3) {
                                    cout << "\nНавык уже максимального уровня\n";
                                    break;
                                }
                                perks[i].UpgradePerk();
                                cout << "\nНавык улучшен\n";
                            }
                        break;
                    case 2:
                        for (int i = 0; i < 4; i++)
                            if (perks2->GetName() == perks[i].GetName()){
                                if (perks[i].GetStage() == 3) {
                                    cout << "\nНавык уже максимального уровня\n";
                                    break;
                                }
                                perks[i].UpgradePerk();
                                cout << "\nНавык улучшен\n";
                            }
                        break;
                }
            }
            for (int i = 0; i < 4; i++){
                if (perks[i].GetName() != "") {
                    int stat = Format::FormatForPerkBonusStats(perks[i].GetAction());
                    string act ="";
                    for (int j = 0; j < 2; j++){
                        if (!isdigit(perks[i].GetAction()[j]))
                            act += perks[i].GetAction()[j];
                    }
                    if (act == "D")
                        Damage+=stat;
                    else if (act == "A")
                        Armor+=stat;
                    else if ( act == "I")
                        Intellect+=stat;
                    else
                        MagicStrength+=stat;
                }
            }
        }
        for (int i= 0;i < 10; i++)
            if (army[i].GetName() != "")//todo апейт статов армии
                army[i].AddHeroStats(Damage, Armor, HP);
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
        nums = Format::FormatForBonusStats(item.GetStats());
        Damage += nums[0];
        HP += nums[1];
        Armor += nums[2];
        Intellect += nums[3];//todo плюс статы от шмоток
        MagicStrength += nums[4];
        for (int i = 0; i<10; i++)
            if (army[i].GetName() != "")
                army[i].AddHeroStats(nums[0], nums[2], nums[3]);
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
        nums = Format::FormatForBonusStats(Equiped[index - 1].GetStats());
        Damage -= nums[0];
        HP -= nums[1];//todo минус статы от шмоток
        Armor -= nums[2];
        Intellect -= nums[3];
        MagicStrength -= nums[4];
            for (int i = 0; i<10; i++)
                if (army[i].GetName() != "")
                    army[i].AddHeroStats(nums[0], nums[2], nums[1]);
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

    void ShowPerks(){
        cout<<"Навыки: \n\n";
        for (int i = 0; i < 4; i++)
            if (perks[i].GetName() != "")
                cout << i+1 << ") " << perks[i].GetName()<< " : "<<Format::PerkDeFormat(perks[i].GetAction());
            else
                cout << i+1 << ") Пусто\n";
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

    void ViewInventory(){
        view:
        cout << "Выберите, что хотите посмотреть: \n1) Армия\n2) Экипировка\n3) Книга заклинаний\n4) Навыки\n5) Характеристики героя\n6) Инвентарь\n7) Назад";
        int j = NULL;
        cin >> j;
        switch (j) {
            case 1:
                system("cls");
                for (int i = 0; i < 10; i++){
                    if (army[i].GetName() != "")
                        cout << i+1 << ") " << army[i].GetName() << ", Урон: " << army[i].GetDamage() <<  ", Здоровье: " << army[i].GetHP()<< ", Броня: " << army[i].GetArmor() << " , Количество юнитов: "<< army[i].GetAmount() << endl;
                    else cout << i+1 << ") Пусто\n";
                }
                cout << "\nНажмите любую кнопку, чтобы выйти\n";
                while (!kbhit());
                system("cls");
                goto view;
            case 2:
                system("cls");
                ShowEquiped();
                cout << "\nНажмите любую кнопку, чтобы выйти\n";
                while (!kbhit());
                system("cls");
                goto view;
            case 3:
                system("cls");
                for (int i = 0; i < MagicBook.size(); i++){
                    cout << i+1 << " ) " << MagicBook[i].GetName() <<" ,Стихия: "<< MagicBook[i].GetStih() << " , Тип: "<<MagicBook[i].GetType();
                    if (MagicBook[i].GetType() == "Damage")
                        cout << " , Урон: "<< MagicBook[i].GetDamage();
                    else
                        cout << " , Длительность: "<< MagicBook[i].GetDuration();
                    cout << " , Уровень: " << MagicBook[i].GetLevel() << " , Затраты маны: "<< MagicBook[i].GetMCost() << endl;
                }
                cout << "\nНажмите любую кнопку, чтобы выйти\n";
                while (!kbhit());
                system("cls");
                goto view;
            case 4:
                system("cls");
                ShowPerks();
                cout << "\nНажмите любую кнопку, чтобы выйти\n";
                while (!kbhit());
                system("cls");
                goto view;
            case 5:
                system("cls");
                ShowStats();
                cout << "\nНажмите любую кнопку, чтобы выйти\n";
                while (!kbhit());
                system("cls");
                goto view;
            case 6:
                system("cls");
                ShowInventory();
                cout << "\nНажмите любую кнопку, чтобы выйти\n";
                while (!kbhit());
                system("cls");
                goto view;
            case 7:
                system("cls");
                break;
        }
    }//метод возможности челикса проверить все свои поля

    int GetGold()
    {
        return this->Gold;
    }
    int GetDamage()
    {
        return this->Damage;
    };
    int GetHP(){
        return this->HP;
    }
    int GetArmor(){
        return Armor;
    }
    int GetIntellect()
    {
        return this->Intellect;
    }
    int GetMagicStrength(){
        return MagicStrength;
    }
    int GetMana()
    {
        return this->Mana;
    }
    int GetMAXmana()
    {
        return this->MAXmana;
    }

    void SetGold(int gold){
        Gold = gold;
    }
    void SetDamage(int damage){
        Damage = damage;
    }
    void SetHP(int hp){
        HP = hp;
    }
    void SetArmor(int armor){
        Armor = armor;
    }
    void SetIntellect(int intellect){
        Intellect = intellect;
    }
    void SetMagicStrength(int magicstrength){
        MagicStrength = magicstrength;
    }
    void SetMana(int Mana)
    {
        this->Mana = Mana;
    }
    void SetMAXmana(int maxmana){
        MAXmana = maxmana;
    }
    void Win(){
        int bExp = 0;
        int bGold = 0;
        for (int i = 0; i < 4; i++){
            if (perks[i].GetName() == "Ученый")
                bExp = perks[i].GetStage()*2;
            if (perks[i].GetName() == "Золотое касание")
                bGold = perks[i].GetStage()*50;
        }
        int getGold = Randomize::GetRand(150,300) + bGold;
        int getXp = Randomize::GetRand(3,5)+ bExp;
        cout << "За победу вы получили "<< getGold<< " золота и "<<getXp<<" опыта\n";
        Gold += getGold;
        GetXp(getXp);
        int DropItem = Randomize::GetRand(1,5);
        if (DropItem == 1){
            Equipment q;
            cout << "\nВам выпал новый предмет!";
            AddToInventory(q);
            Inventory.push_back(q);
        }
    }
    void Lose(){
        int loseHP = Randomize::GetRand(5,10);
        int loseGold = Gold * Randomize::GetRand(20,30)/100;
        cout << "Вы потеряли "<< loseHP << " здоровья и "<< loseGold<< "золота!\n";
        cout << "Вас жестко отпинали и бросили в каком-то городе неподалеку...\n";
        HP -= loseHP;
        Gold -= loseGold;
        Sleep(2000);
        HeroDeath();
    }
    bool HeroDeath()//todo смээээээрт
   {
       if (HP == 0){
           cout << "Ты сдох чел, Я не могу поверить, мы столько времени с тобой провели...\n И как все закончилось... Покойся с миром\n";
           return true;
       }
   }
    Spells CastSpell()
    {
        if (this->MagicBook.empty()) {
            cout << "Вы еще не знаете никаких заклинаний";

        }
        else {
            cout << "Ваша мана : " << this->Mana << " \n";
            cout << "Возможные к касту заклинания: \n";
            int i = 0;
            for ( i = 0; i <MagicBook.size(); i++)
            {
                //Name, Stih, Type, to_string(Damage), to_string(Distance), to_string(Duration), to_string(Level), to_string(MCost), to_string(GCost)
                if (MagicBook[i].GetMCost() <= this->Mana && MagicBook[i].GetLevel() <= this->MagicStrength)
                cout << i + 1 <<". " << MagicBook[i].GetName() << " стоимость - " << MagicBook[i].GetMCost() << " маны \n";
                else
                    i--;
            }
            if (i == 0)
                cout << "Нет доступных заклинаний для каста \n";
            else
            {
                cout << "Введите номер заклинания для каста \n";
                int j;
                cin >> j;
                return MagicBook[j-1];
            }
        }
    }

};


#endif //UNTITLED3_HERO_H
