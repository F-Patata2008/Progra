#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;
typedef string str;
#define vec vector


int main() {
    int r, a, b, x, y;
    cin >> r;
    cin >> a >> b;
    cin >> x >> y;


    if (a == x && b == y) {
        cout << 0 << endl;
        return 0;
    }
    else {
        double dist = sqrt(pow((x - a),  2) + pow((y - b),  2))/2;
        dist /= r;
        cout << ceil(dist) << endl;
        return 0;
    }

    return 0;
}

