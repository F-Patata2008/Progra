#include <bits/stdc++.h>
#include <set>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    multiset<ll> bolsa;
    int p;
    ll x, a = 0;
    while (t--) {
        cin >> p;

        if (p == 1) {
            cin >> x;
            bolsa.insert(x);
        }

        if (p == 2) {
            cin >> x;
            a += x;
        }

        if (p == 3) {
            cout << *bolsa.begin() + a << endl;
            if (bolsa.end() != bolsa.begin()) bolsa.erase(bolsa.begin());
        }

    }

    cout << endl;
    return 0;
}
