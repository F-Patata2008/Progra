#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int sweet, sour;
    while (cin >> sweet >> sour) {
        if (sweet+sour==13) cout << "Never speak again." << "\n";
        else if (sweet+sour==0) break;
        else if (sweet>sour) cout << "To the convention." << "\n";
        else if (sweet<sour) cout << "Left beehind." << "\n"; 
        else if (sweet==sour) cout << "Undecided." << "\n";
    }
    return 0;
}
