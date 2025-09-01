#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int r;
    int x, y;
    int a, b;
    cin >> r >> x >> y >> a >> b;

    if (a == x && b == y) {
        cout << 0 << endl;
        return 0;
    }
   

    double dist = sqrt(pow((a - x),  2) + pow((b - y),  2))/2;

    dist =  dist/r;

    cout << ceil(dist) << endl;

    return 0;
}
