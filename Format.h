//
// Created by user on 06.03.2021.
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
        vector<string> arr;
        string delim = "_";
        size_t prev = 0;
        size_t next;
        size_t delta = 1;

        while( ( next = format.find( delim, prev ) ) != string::npos ){
            string tmp = format.substr( prev, next-prev );
            cout << tmp << endl;

            arr.push_back( format.substr( prev, next-prev ) );
            prev = next + delta;
        }
        string tmp = format.substr( prev );
        cout << tmp << endl;

        arr.push_back( format.substr( prev ) );

        return "";
    }
};


#endif //MAIN_CPP_FORMAT_H
