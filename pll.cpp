#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <algorithm>

#include "Timer.h"

using namespace std;

void hide_cursor(){
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

int main() {
    Timer watch;
	vector<string> pll = {"A(a)", "A(b)", "T", "F", "V", "U(b)", "Z", "H", "J(a)", "J(b)", "N(a)", "N(b)", "E", "G(a)", "G(b)", "G(c)", "G(d)", "Y", "R(a)", "R(b)"};
    hide_cursor();

	cout << "Start";
	while (_getch() == ' '){
        system("CLS"); 
        random_shuffle(pll.begin(), pll.end());
        for (auto T : pll)
            cout << T << " ";
        watch.elapseTime();
        _getch();
    }

	return 0;
}
