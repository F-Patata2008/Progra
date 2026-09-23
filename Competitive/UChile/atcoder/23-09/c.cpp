#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    ll n;
    cin >> n;
    vec<int> b(n, 0);
    map<int, int> a, c;

    ll aux;
    for (ll i = 0; i < n; i++) {
        cin >> aux;
        a[ aux ]++;
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[ i ];
    }

    for (ll i = 0; i < n; i++) {
        cin >> aux;
        c[ aux ]++;
    }

    ll cont = 0;
    for (auto act : c) {
        cont += (act.second * a[ b[ act.first ] ]);
    }


    cout << cont << endl;


    return 0;
}
