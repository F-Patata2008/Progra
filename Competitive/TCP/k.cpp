#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

const ll MOD = 1e9 +7;

vec <ll> mem;
vec <ll> fac;

ll dp (int n) {
    
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (mem[n] == -1) {
        mem[n] = (fac[n] + 2 * dp(n - 1)) % MOD;
    }

    return mem[n] % MOD;
}


int main() {
    int n;
    cin >> n;

    mem.resize(n, -1);
    fac.resize(n, -1);
    
    fac[0] = 1;
    for (int i = 1; i < n; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    


    cout << dp(n - 1) << endl;

    return 0;
}
