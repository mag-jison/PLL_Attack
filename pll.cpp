#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <algorithm>

#include "Timer.h"

using namespace std;

int main() {
    Timer watch;
	vector<string> pll = {"A(a)", "A(b)", "T", "F", "V", "U(b)", "Z", "H", "J(a)", "J(b)", "N(a)", "N(b)", "E", "G(a)", "G(b)", "G(c)", "G(d)", "Y", "R(a)", "R(b)"};
    watch.hide_cursor();

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
