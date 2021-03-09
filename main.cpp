#include <iostream>
#include <string>
#include <windows.h>
#include "Equipment.h"
#include "Randomize.h"
#include "Hero.h"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    /*start:
    system("cls");
    Sleep(1000);
    cout << "1" << endl;
    Sleep(1000);
    cout << "2" << endl;
    Sleep(1000);
    cout << "3" << endl;
    Sleep(1000);
    std::cout << "Ну что, готов окунуться в этот мир, полный приключений,\n"
                 "существ, опасностей и гачистов?\n"
                 "Если да, то напиши WE-WE POWER: ";
    string a;
    getline(cin, a);
    cout << endl;
    if (a != "WE-WE POWER") {
        cout << "Ну ты че, давай нормально" << endl;
        goto start;
    }*/
    st:
    cout << "Введите класс персонажа: \n1) Лучник\n2) Воин\n3) Волшебник\n" ;
    int index;
    cin >> index;
    if (index > 3 || index < 1) goto st;
    Hero *MainHero = new Hero(index);

    Equipment *q = new Equipment();
    if (q->DropEquipment() == 1)
        MainHero.Equip(q);
    else
        MainHero->AddToInventory(*q);
    cout << size(MainHero->Inventory) << endl;
    cout << "Персонаж успешно создан";
    return 0;
}
