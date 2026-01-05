#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

vec<ll> mem;
map<ll,ll> a;


//Max Score desde 0 hasta i
ll solve (ll n) {
    if (n < 1) return 0;
    if (mem[n] != -1) return mem[n];

    mem[n] = max(a[n]*n + solve(n-2),solve(n-1));

    //cout << a[n] << " " << mem[n] << endl;
    return mem[n];
}


int main() {
    ll best = 0;
    ll tam;
    cin >> tam;
    ll max = 0;


    for (ll i = 0; i < tam; i++) {
        ll ussr;
        cin >> ussr;
        if (ussr > max) max = ussr;
        if (a.find(ussr) != a.end()) a[ussr]++;
        else a[ussr] = 1;
    }

    mem.resize(max+1, -1);

    cout << solve(max) << endl;


    return 0;
}
