#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    str ussr;
    cin >> ussr;

    int dir = 0; // 0 es este, 1 sur, 2 oeste, 3 norte y 4 este nuevamemnte
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (ussr[ i ] == 'S') {
            dir = dir % 4;

            switch (dir) {
            case 0:
                x++;
                break;
            case 1:
                y--;
                break;
            case 2:
                x--;
                break;
            case 3:
                y++;
                break;
            }
        } else
            dir++;
    }
    cout << x << " " << y << endl;


    return 0;
}
