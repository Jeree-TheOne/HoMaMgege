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
    int ekipirovka;
    int helmet=0; //переменные в которых написано одет пользователь или нет, если да, то во что
    int breastplace=0; //НОРМАЛЬНЫЙ НЕЙМИНГ ЧЁ ТЕБЕ НЕ НРАВИТСЯ?
    int lefthand=0;
    int righthand=0;
    int legs=0;
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
        if (ekipirovka == 1) //ар это оружие, сейчас переименую, каждому предмету присваивается своё число
            cout << "Шлем белого единорога" << endl;
        else if (ekipirovka == 2)
            cout << "Шлем Хаоса" << endl;
        else if (ekipirovka == 3)
            cout << "Шлем небесного грома" << endl;

        if (ekipirovka == 4)
            cout << "Туника короля циклопов" << endl;
        else if (ekipirovka == 5)
            cout << "Доспех из чешуи дракона" << endl;
        else if (ekipirovka == 6)
            cout << "Кираса титана" << endl;

        if (ekipirovka == 7)
            cout << "Щит короля гномов" << endl;
        else if (ekipirovka = 8)
            cout << "Щит тоскующих мертвецов" << endl;
        else if (ekipirovka == 9)
            cout << "Щит из чешуи дракона" << endl;

        if (ekipirovka == 10)
            cout << "Гладиус титана" << endl;
        else if (ekipirovka == 11)
            cout << "Карающая дубина огра" << endl;
        else if (ekipirovka == 12)
            cout << "Секира кентавра" << endl;

        if (ekipirovka == 13)
            cout << "Сапоги левитации" << endl;
        else if (ekipirovka == 14)
            cout << "Башмаки мертвеца" << endl;
        else if (ekipirovka == 15)
            cout << "Сандалии святого" << endl;


        inventar.push_back(ekipirovka);//Записывает полученную вещь (если её там нет) в конец листа
    }
        if (ekipirovka==1||ekipirovka==2||ekipirovka==3) //предоставляет выбор надеть полученную броню или нет
        {
            cout << "Желаете надеть шлем?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch (i) {
                case 1:
                    helmet = ekipirovka; //если да, вещи меняются
                    break;
                case 2:
                    helmet = helmet; //если нет вещь остаётся на месте
                    break;
            }
        }
        else if (ekipirovka==4||ekipirovka==5||ekipirovka==6){
            cout << "Желаете надеть нагрудник?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch (i) {
                case 1:
                    breastplace = ekipirovka;
                    break;
                case 2:
                    breastplace = breastplace;
                    break;
            }
        }
        else if (ekipirovka==7||ekipirovka==8||ekipirovka==9){
            cout << "Желаете надеть щит?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch (i) {
                case 1:
                    lefthand = ekipirovka;
                    break;
                case 2:
                    lefthand = lefthand;
                    break;
            }
        }
        else if (ekipirovka==10||ekipirovka==11||ekipirovka==12){
            cout << "Желаете взять оружие?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch (i) {
                case 1:
                    righthand = ekipirovka;
                    break;
                case 2:
                    righthand = righthand;
                    break;
            }
        }
        else if (ekipirovka==13||ekipirovka==14||ekipirovka==15){
            cout << "Желаете надеть обувь?" << endl;
            cout << "1)Да" << endl;
            cout << "2)Нет" << endl;
            cin >> i;
            switch (i) {
                case 1:
                    legs = ekipirovka;
                    break;
                case 2:
                    legs = legs;
                    break;
            }
        }
    }
    void EquipEquipment(string name, int damage, int hp, int armor, int intellect, int magicstrength){

    }
};


#endif //UNTITLED3_EQUIPMENT_H
