//
// Created by JerEe^ on 01.03.2021.
//

#ifndef UNTITLED3_PERKS_H
#define UNTITLED3_PERKS_H

#include <iostream>

class Perk {
private:
    std::string Name;
    std::string Action;
    int Stage;
    int Chance;
    std::string perks [12][3] = {
            {"Стрельба"},
            {"Удача"},
            {"Уклонение"},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""},
            {""}
    };
    //BATYGINA OTRABOTIVAI
public:
    void AddPerk(std::string name) {
        
    }
    void UpgradePerk(std::string name, std::string action, int stage){

    }
};


#endif //UNTITLED3_PERKS_H
