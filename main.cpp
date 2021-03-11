#include <iostream>
#include <string>
#include <windows.h>
#include "Equipment.h"
#include "Randomize.h"
#include "Hero.h"
#include <ctime>
#include "Units.h"
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
    cout << "Персонаж успешно создан\n";


    MainHero->ShowStats();

    MainHero->GetXp(10);

    MainHero->ShowStats();
    /*srand(time(NULL));
    array<int,10> a = {0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < 100000; i++)
        a[rand() % 10]++;
    for (int i = 0; i < size(a);i++)
        cout <<i << ": " << a[i] << endl;*/


    return 0;
}
