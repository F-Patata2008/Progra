#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int x, y;
    cin >> x >> y;


    if (y - x < 0) {
        cout << 0;
    } else {
        int cont = 0;
        y -= x;
        while (y > 0) {
            y -= 10;
            cont++;
        }
        cout << cont;
    }
    cout << endl;

    return 0;
}
