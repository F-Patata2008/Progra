#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

int main() {
    int tiendas;
    cin >> tiendas;
    vec<int> Precios(tiendas);
    for (int i = 0; i < tiendas; i++) {
        cin >> Precios[i];
    }

    sort(Precios.begin(), Precios.end());
    int dias;
    cin >> dias;
    vec<int> Sueldo(dias);
    for (int i = 0; i < dias; i++) {
        cin >> Sueldo[i];
    }

    for (int i = 0; i < dias;i++) {
        vec<int>::iterator posibles;
        int Dia = Sueldo[i];
        posibles = upper_bound(Precios.begin(), Precios.end(), Dia);
        cout << posibles -Precios.begin() << endl;

    }

    return 0;
}