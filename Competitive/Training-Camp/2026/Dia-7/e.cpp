#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

void solve() {
    int n, k;
    cin >> n >> k;

    vec<ll> a(n);
    vec<ll> b(n);
    vec<ll> precios; // Candidatos a precio óptimo

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        precios.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        precios.push_back(b[i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    sort(precios.begin(), precios.end());
    precios.erase(unique(precios.begin(), precios.end()), precios.end());

    ll max_ganancia = 0;

    for (ll p : precios) {
        
        int no_compran = lower_bound(b.begin(), b.end(), p) - b.begin();
        int compran = n - no_compran;

        int infelices_total = lower_bound(a.begin(), a.end(), p) - a.begin();

        int reviews_negativos = infelices_total - no_compran;

        if (reviews_negativos <= k) {
            ll ganancia_actual = p * compran;
            max_ganancia = max(max_ganancia, ganancia_actual);
        }
    }

    cout << max_ganancia << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
