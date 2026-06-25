#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    ll n, p, w, d;
    cin >> n >> p >> w >> d;

    for (ll i = 0; i < w; i++) {
        ll vik = p-(i*d);
        if (vik<0) continue;

        if(vik%w == 0) {
            ll x = vik/w;
            if (x+i<=n) {
                cout << x << " " << i << " " << n-x-i << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
