#include <iostream>
#include <string>
#include <windows.h>
#include "Equipment.h"
using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8);
    start:
    system("cls");
    Sleep(1000);
    cout << "1" << endl;
    Sleep(1000);
    cout << "2" << endl;
    Sleep(1000);
    cout << "3" << endl;
    Sleep(1000);
    /*std::cout << "Ну что, готов окунуться в этот мир, полный приключений,\n"
                 "существ, опасностей и гачистов?\n"
                 "Если да, то напиши WE-WE POWER: ";
    string a;
    getline(cin, a);
    cout << endl;
    if (a != "WE-WE POWER") {
        cout << "Ну ты че, давай нормально" << endl;
        goto start;
    }*/

    Equipment qq("","","");
    qq.DropEquipment(3);
    return 0;
}
