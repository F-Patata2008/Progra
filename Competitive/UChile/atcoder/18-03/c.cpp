#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    // Numero de dias

    int d, p;
    cin >> d >> p;
    // D pases por un precio de P pesos

    /* si compor D pases diarios
     * debo suarlos en los D dias mas caros, si es que las suma de lso boletos esos dia  >= P
     * */

    vec<int> precios (n, -1);
    int cp = n;
    for (int i = 0; i < n; i++) cin >> precios[i];


    return 0;
}
