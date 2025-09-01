#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    ll n;
    cin >> n;
    vec <ll> x(n);

    for (ll i = 0; i < n; i++) {
        cin >> x[i];
    }

    ll sum = 0;
    for (ll i = 0; i < n - 1; i++) {
        if (x[i] > x[i + 1]) {
            sum += x[i] - x[i + 1];
            x[i + 1] += x[i] - x[i + 1];
        }
    }

    cout << sum << endl;

    return 0;
}
