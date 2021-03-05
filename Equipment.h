//
// Created by JerEe^ on 01.03.2021.
//

#ifndef UNTITLED3_EQUIPMENT_H
#define UNTITLED3_EQUIPMENT_H
#include <iostream>
using namespace std;
class Equipment {
private:
    string Name;
    int Damage;
    int HP;
    int Armor;
    int Intellect;
    int MagicStrength;
    int helmet;
    int breastplate;
    int righthand;
    int lefthand;
    int legs;
    int sh=0;
    int grud=0;
    int ruk1=0;
    int ruk2=0;
    int nog=0;
    void CreateEquipment(string name, int damage, int hp, int armor, int intellect, int magicstrength){
int i;
        cout << "Вам выпал: ";
       if (helmet==1)
           cout << "Шлем белого единорога" << endl;
        else if (helmet==2)
            cout << "Шлем Хаоса" << endl;
        else if (helmet==3)
            cout << "Шлем небесного грома" << endl;
        else {
           cout << "Желаете надеть шлем?" << endl;
           cout << "1)Да" << endl;
           cout << "2)Нет" << endl;
           cin >> i;
            switch(i){
            case 1:
                sh = helmet;
                break;
            case 2:
                sh = sh;
                break;
        }
        }
        if (breastplate==1)
            cout << "Туника короля циклопов" << endl;
        else if (breastplate==2)
            cout << "Доспех из чешуи дракона" << endl;
        else if (breastplate==3)
            cout << "Кираса титана" << endl;
        else {
            cout << "Желаете надеть нагрудник?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch(i){
                case 1:
                    grud = breastplate;
                    break;
                case 2:
                    grud = grud;
                    break;
            }
        }
        if (lefthand==1)
            cout << "Щит короля гномов" << endl;
        else if (lefthand==2)
            cout << "Щит тоскующих мертвецов" << endl;
        else if (lefthand==3)
            cout << "Щит из чешуи дракона" << endl;
        else {
            cout << "Желаете надеть щит?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch(i){
                case 1:
                    ruk1 = lefthand;
                    break;
                case 2:
                    ruk1 = ruk1;
                    break;
            }
        }
        if (righthand==1)
            cout << "Гладиус титана" << endl;
        else if (righthand==2)
            cout << "Карающая дубина огра" << endl;
        else if (righthand==3)
            cout << "Секира кентавра" << endl;
        else {
            cout << "Желаете взять оружие?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch(i){
                case 1:
                    ruk2 = righthand;
                    break;
                case 2:
                    ruk2 = ruk2;
                    break;
            }
        }
        if (legs==1)
            cout << "Сапоги левитации" << endl;
        else if (legs==2)
            cout << "Башмаки мертвеца" << endl;
        else if (legs==3)
            cout << "Сандалии святого" << endl;
        else {
            cout << "Желаете надеть обувь?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch(i){
                case 1:
                    nog = helmet;
                    break;
                case 2:
                    nog = nog;
                    break;
            }
        }
    }
    void EquipEquipment(string name, int damage, int hp, int armor, int intellect, int magicstrength){

    }
};


#endif //UNTITLED3_EQUIPMENT_H
