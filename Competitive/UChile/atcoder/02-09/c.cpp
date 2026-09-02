#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    ll n, x;
    cin >> n >> x;

    vec<map<ll, ll>> bolsas(n);

    for (ll i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int act;
            cin >> act;
            bolsas[ i ][ act ]++;
        }
    }
    ll cont = 0;
    for (auto i : bolsas[ 0 ]) {
        ll conti = i.second;
        ll punt = x / i.first;
    }


    return 0;
}
