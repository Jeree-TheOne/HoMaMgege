//
// Created by JerEe^ on 01.03.2021.
//

#ifndef UNTITLED3_EQUIPMENT_H
#define UNTITLED3_EQUIPMENT_H
#include <iostream>


using namespace std;
template<typename T>
class Equipment {
private:

    string Name;
    int Damage;
    int HP;
    int Armor;
    int Intellect;
    int MagicStrength;
    int ar;
    int sh=0; //переменные в которых написано одет пользователь или нет, если да, то во что
    int grud=0; //НОРМАЛЬНЫЙ НЕЙМИНГ ЧЁ ТЕБЕ НЕ НРАВИТСЯ?
    int ruk1=0;
    int ruk2=0;
    int nog=0;
    void CreateEquipment(string name, int damage, int hp, int armor, int intellect, int magicstrength) {
        int i;
        int y;//переменная которая будет коннектиться с рандомом
        list<int> inventar; //объявление листа
        for (auto inv = inventar.begin(); inv!=inventar.end();inv++) //перебирание всех элементов листа
        if (*inv == y) //проверка на существование этого элемента в листа, то есть в инвентаре, если такой предмет есть тебя шлют нахуй
        cout<<"К сожалению у вас есть уже такой инвентарь";
        else //далее идёт запись в лист и разговор с пользователем
        {
        cout << "Вам выпал: ";
        if (ar == 1) //ар это оружие, сейчас переименую, каждому предмету присваивается своё число
            cout << "Шлем белого единорога" << endl;
        else if (ar == 2)
            cout << "Шлем Хаоса" << endl;
        else if (ar == 3)
            cout << "Шлем небесного грома" << endl;
        else {
            cout << "Желаете надеть шлем?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch (i) {
                case 1:
                    sh = ar;
                    break
                case 2:
                    sh = sh;
                    break;
            }
        }
        if (ar == 4)
            cout << "Туника короля циклопов" << endl;
        else if (ar == 5)
            cout << "Доспех из чешуи дракона" << endl;
        else if (ar == 6)
            cout << "Кираса титана" << endl;
        else {
            cout << "Желаете надеть нагрудник?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch (i) {
                case 1:
                    grud = ar;
                    break;
                case 2:
                    grud = grud;
                    break;
            }
        }
        if (ar == 7)
            cout << "Щит короля гномов" << endl;
        else if (ar = 8)
            cout << "Щит тоскующих мертвецов" << endl;
        else if (ar == 9)
            cout << "Щит из чешуи дракона" << endl;
        else {
            cout << "Желаете надеть щит?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch (i) {
                case 1:
                    ruk1 = ar;
                    break;
                case 2:
                    ruk1 = ruk1;
                    break;
            }
        }
        if (ar == 10)
            cout << "Гладиус титана" << endl;
        else if (ar == 11)
            cout << "Карающая дубина огра" << endl;
        else if (ar == 12)
            cout << "Секира кентавра" << endl;
        else {
            cout << "Желаете взять оружие?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch (i) {
                case 1:
                    ruk2 = ar;
                    break;
                case 2:
                    ruk2 = ruk2;
                    break;
            }
        }
        if (ar == 13)
            cout << "Сапоги левитации" << endl;
        else if (ar == 14)
            cout << "Башмаки мертвеца" << endl;
        else if (ar == 15)
            cout << "Сандалии святого" << endl;
        else {
            cout << "Желаете надеть обувь?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch (i) {
                case 1:
                    nog = ar;
                    break;
                case 2:
                    nog = nog;
                    break;
            }
        }

        inventar.push_back(ar);
    }
    }
    void EquipEquipment(string name, int damage, int hp, int armor, int intellect, int magicstrength){

    }
};


#endif //UNTITLED3_EQUIPMENT_H
