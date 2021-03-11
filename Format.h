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



    static string DeFormat(string format) {
        string stats[6] = {"Урон", "Здоровье", "Броня", "Интеллект", "Магическая сила", "Стоимость"};
        vector<string> arr;
        string delim("_");
        size_t prev = 0;
        size_t next;
        size_t delta = delim.length();
        int index = 0;
        string res;
        while ((next = format.find(delim, prev)) != string::npos) {
            string tmp = format.substr(prev, next - prev);
            if (stoi(tmp) != 0)
                res += stats[index] + ": " + tmp + "\n";
            ++index;
            arr.push_back(format.substr(prev, next - prev));
            prev = next + delta;
        }
        string tmp = format.substr(prev);
        if (stoi(tmp) != 0)
            res += stats[index] + ": " + tmp + "\n";
        arr.push_back(format.substr(prev));

        return res;

    }

    static string PerkDeFormat(string action) {
        string stats[6] = {"Бонус к урону", "Бонус к опыту", "Бонус к броне", "Бонус к магической силе",
                           "Бонус к интеллекту", "Бонус к золоту"};
        string num, act, res;
        for (int i = 0; i < action.length(); i++) {
            if (isdigit(action[i]))
                num += action[i];
            else
                act += action[i];
        }
        if (act == "D")
            res = stats[0] + " - " + num + "\n";
        else if (act == "E")
            res = stats[1] + " - " + num + "\n";
        else if (act == "A")
            res = stats[2] + " - " + num + "\n";
        else if (act == "MS")
            res = stats[3] + " - " + num + "\n";
        else if (act == "I")
            res = stats[4] + " - " + num + "\n";
        else if (act == "G")
            res = stats[5] + " - " + num + "\n";
        return res;
    }
    static int* FormatForPerkBonusStats(string action){
        string stats[4] = {"D","A","I","MS"};
        int nums[4] = {0, 0, 0, 0};
        string num, act;
        for (int i = 0; i < action.length(); i++) {
            if (isdigit(action[i]))
                num += action[i];
            else
                act += action[i];
        }
        if (act == "D")
            nums[0] = stoi(num);
        else if (act == "A")
            nums[1] = stoi(num);
        else if (act == "I")
            nums[2] = stoi(num);
        else if (act == "MS")
            nums[3] = stoi(num);
        return nums;
    }

    static string UpPerk(string action, int stage) {
        string num, act;
        for (int i = 0; i < action.length(); i++) {
            if (isdigit(action[i]))
                num += action[i];
            else
                act += action[i];
        }
        num = to_string(stoi(num) / stage * (stage + 1));
        return act + num;
    }

    static int *FormatForBonusStats(string format) {
        string stats[6] = {"Урон", "Здоровье", "Броня", "Интеллект", "Магическая сила", "Стоимость"};
        int nums[6] = {0, 0, 0, 0, 0, 0};
        vector<string> arr;
        string delim("_");
        size_t prev = 0;
        size_t next;
        size_t delta = delim.length();
        int index = 0;
        string res;
        while ((next = format.find(delim, prev)) != string::npos) {
            string tmp = format.substr(prev, next - prev);
            if (stoi(tmp) != 0)
                nums[index] = stoi(tmp);
            ++index;
            arr.push_back(format.substr(prev, next - prev));
            prev = next + delta;
        }
        string tmp = format.substr(prev);
        if (stoi(tmp) != 0)
            res += stats[index] + ": " + tmp + "\n";
        arr.push_back(format.substr(prev));

        return nums;

    }
};

#endif //MAIN_CPP_FORMAT_H
