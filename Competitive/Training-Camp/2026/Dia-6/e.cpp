#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector
int n;
ll k;
vec<ll> receta;
vec<ll> disp;


bool hornar(ll num_galletas_a_probar) {
    ll polvo_magico = 0;

    for (int i = 0; i < n; i++) {
        ll total_necesario = receta[i] * num_galletas_a_probar;
        if (disp[i] < total_necesario) {
            polvo_magico += total_necesario - disp[i];
        }
        if (polvo_magico > k) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> n >> k;
    receta.resize(n);
    disp.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> receta[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> disp[i];
    }

    ll izq, der, mid;
    ll respuesta = 0;
    izq = 0;
    der = 2000000007;

    while (izq <= der) {
        mid = izq + (der - izq) / 2;
        if (hornar(mid)) {
            respuesta = mid;
            izq = mid + 1;
        } else {
            der = mid - 1;
        }
    }

    cout << respuesta << endl;

    return 0;
}
