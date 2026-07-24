#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, m;
    cin >> n >> m;

    map<ll, ll> mapa;

    ll ussr;
    for (int i = 0; i < n; i++) {
        cin >> ussr;
        mapa[ ussr % m ]++;
    }

    ll cont = 0;
    for (auto p : mapa) {
        if (p.second > 1)
            cont += p.second;
    }

    cout << cont << endl;
    return 0;
}
