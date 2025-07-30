#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

const int MAX = 1000001;
vector<bool> primos(MAX, true);
void sieve() {
    primos[0] = primos[1] = 0;
    for (int i = 2; i * i < MAX; i++) {
        if (primos[i]) {
            for (int j = i * i; j < MAX; j += i)
                primos[j] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    sieve();

    vec <ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        ll raiz = round(sqrt(a[i]));
        if (a[i] == 4) cout << "YES\n";
        else if (a[i] % 2 == 0) cout << "NO\n";
        else if ((raiz * raiz == a[i]) && raiz < MAX && primos[raiz]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
