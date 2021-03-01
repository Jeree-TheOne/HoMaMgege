#include <iostream>
#include <string>
#include <windows.h>
int main() {
    SetConsoleOutputCP(CP_UTF8);
    start:
    system("cls");
    Sleep(1000);
    std::cout << "1" << std::endl;
    Sleep(1000);
    std::cout << "2" << std::endl;
    Sleep(1000);
    std::cout << "3" << std::endl;
    Sleep(1000);
    std::cout << "Ну что, готов окунуться в этот мир, полный приключений,\n"
                 "существ, опасностей и гачистов?\n"
                 "Если да, то напиши WE-WE POWER: ";
    std::string a;
    std::getline(std::cin, a);
    std::cout << std::endl;
    if (a != "WE-WE POWER"){
        std::cout << "Ну ты че, давай нормально" << std::endl;
        goto start;
    }
    std::cout << "a";
    return 0;
}
