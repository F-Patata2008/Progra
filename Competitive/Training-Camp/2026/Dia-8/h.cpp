#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;

    map<int, int> Xcord;
    map<int, int> Ycord;

    map<pair<int, int>, int> dup;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        Xcord[x]++;
        Ycord[y]++;
        dup[{x, y}]++;
    }
    ll sum = 0;

    for (auto & [x, cont] : Xcord) sum += (ll) cont * (cont - 1) / 2;
    for (auto & [y, cont] : Ycord) sum += (ll) cont * (cont - 1) / 2;
    for (auto & [d, cont] : dup  ) sum -= (ll) cont * (cont - 1) / 2;
    cout << sum << endl;

    return 0;
}
