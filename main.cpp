#include <iostream>
#include <string>
#include <windows.h>
#include "Equipment.h"
#include "Randomize.h"
#include "Hero.h"
#include <ctime>
#include "Units.h"
#include "Battle.h"
#include "Locations.h"
#include "Enterprises.h"
#include "Outside.h"
using namespace std;

 int main() {
    SetConsoleOutputCP(CP_UTF8);
//    _CrtSetDebugFillThreshold(0);
start:
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
}
    st:
    cout << "\nВведите класс персонажа: \n1) Лучник\n2) Воин\n3) Волшебник\n" ;
    int index;
    cin >> index;
    if (index > 3 || index < 1) goto st;

    Hero *MainHero = new Hero(index);
    cout << "Персонаж успешно создан\n";
    while(true) {
        City *Gorod = new City();
        Gorod->EnterTheCity(*MainHero);
        delete Gorod;
        system("cls");
        Outside *Uliza = new Outside();
        Uliza->SetPath(*MainHero);
        Uliza->LeaveTheCity(*MainHero);
        delete Uliza;
    }
    return 0;
}