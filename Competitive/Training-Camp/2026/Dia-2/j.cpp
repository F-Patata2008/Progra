#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;

    str juegos;
    cin >> juegos;

    int cal = 0;
    for (char z : juegos) {
        if (z == '1') cal += a1;
        if (z == '2') cal += a2;
        if (z == '3') cal += a3;
        if (z == '4') cal += a4;
    }

    cout << cal << endl;


    return 0;
}
