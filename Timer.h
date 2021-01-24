#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <list>
#include <iterator>
#include <iomanip>

using namespace std;

class Timer {
private:
    size_t min, sec;
    double average;
    list<int> listTimes;

public:
    Timer(){
        this->min = 0;
        this->sec = 0;
        this->average = 0.0;
    }

    double avg(const list<int>&, const size_t&);
    void elapseTime();
    void hide_cursor();
}; 

double Timer::avg(const list<int>& temp, const size_t& len){
    list<int>::const_iterator it = next(temp.begin(), temp.size()-len);
    if (temp.size() < len)
        return 0.0;

    for (it; it != end(temp); ++it)
        average += *it;

    average /= len;
    return average;
}

void Timer::elapseTime(){
    min = 0, sec = 0;
    while (!_kbhit()){
        sec++;
        Sleep(1000);

        if (sec > 59)
            min++, sec = 0;
    }
    cout << "\n" << sec;
}

void Timer::hide_cursor(){
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
