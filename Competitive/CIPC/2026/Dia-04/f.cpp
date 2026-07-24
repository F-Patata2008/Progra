#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    ll n, B;
    cin >> n >> B;
    vec<ll> d(n), c(n);
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> d[ i ] >> c[ i ];
        sum += d[ i ];
    }

    ll cont = 0;
    ll l = 0;
    ll maxi = 0;
    for (ll r = 1; cont <= B; r++) {
        ll k = 0;
        cont = 0;
        for (ll j = 0; j < n; j++) {
            cont += min(d[ j ], r) * c[ j ];
            k += min(d[ j ], r);
        }
        if (cont <= B) {
            maxi = (ll) max(r, maxi);
            l = max(k, l);
        } else
            break;
    }

    if (sum == l)
        cout << -1 << " " << sum;
    else
        cout << maxi << " " << l;

    cout << endl;

    return 0;
}
