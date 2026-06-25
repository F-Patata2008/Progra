#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int cal[4];
    for (int i = 0; i < 4; i++) cin >> cal[i];
    int sum = 0;
    
    str Juego;
    cin >> Juego;

    for(char i : Juego) {
        if (i == '1') sum+=cal[0];
        if (i == '2') sum+=cal[1];
        if (i == '3') sum+=cal[2];
        if (i == '4') sum+=cal[3];
}

    cout << sum << endl;

    return 0;
}
