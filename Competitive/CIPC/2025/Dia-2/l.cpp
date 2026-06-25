#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    vec<ll> colores(3);
    ll suma=0;
    for (int i = 0; i < 3; i++) {
        cin >> colores[i];
        suma+=colores[i];

        }
    
    sort(colores.begin(), colores.end());

    cout << min((colores[0]+colores[1]), suma/3) << endl; 

    return 0;
}
