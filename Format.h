//
// Created by user on 07.03.2021.
//

#ifndef MAIN_CPP_FORMAT_H
#define MAIN_CPP_FORMAT_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Format {

public:

    static string DeFormat(string format){
        string stats[6] = {"Урон","Здоровье","Броня","Интеллект","Магическая сила","Стоимость"};
        vector<string> arr;
        string delim("_");
        size_t prev = 0;
        size_t next;
        size_t delta = delim.length();
        int index = 0;
        string res;
        while( ( next = format.find( delim, prev ) ) != string::npos ){
            string tmp = format.substr( prev, next-prev );
            if (stoi(tmp) != 0)
                res += stats[index] + ": " + tmp + "\n";
            ++index;
            arr.push_back( format.substr( prev, next-prev ) );
            prev = next + delta;
        }
        string tmp = format.substr( prev );
        if (stoi(tmp) != 0)
            res += stats[index] + ": " + tmp + "\n";
        arr.push_back( format.substr( prev ) );

        return res;

    }
    static string UpPerk(string action, int stage){
        string num,act;
        for(int i = 0; i < action.length(); i++){
            if (isdigit(action[i]))
                num += action[i];
            else
                act += action[i];
        }
        num = to_string(stoi(num) / stage * (stage + 1));
        return act + num;
    }
};


#endif //MAIN_CPP_FORMAT_H
