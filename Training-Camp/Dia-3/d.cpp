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

    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    if (n == 4) return 8;
    if (n == 5) return 16;
    if (n == 6) return 32;
    ll b;
    ll c = 0;
    if (memo[n] != -1) return memo[n];
    for (int i = 1; i < 7; i++) {
        b= supercalc(n-i)%(a+7);
        c = (c+b)%(a+7);
    }
    memo[n] = c%(a+7);
    return memo[n];

}



int main() {
    ll calc;
    cin >> calc;
    memo.resize(calc+1, -1);
    cout << supercalc(calc) << endl;

    return 0;
}