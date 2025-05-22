#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

ll a = 1e9;

vec<ll> memo;

ll supercalc (ll n) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    if (memo[n] != -1) return memo[n];
    memo[n] = max(supercalc(n-2020), supercalc(n-2021));
    return memo[n];

}



int main() {
    int t;
    cin >> t;
    memo.assign(1e6+10, -1);
    while (t--) {
        ll calc;
        cin >> calc;
        if (supercalc(calc) > 0 ) cout << "YES" << endl;
        else cout << "NO" << endl;





    }
    return 0;
}