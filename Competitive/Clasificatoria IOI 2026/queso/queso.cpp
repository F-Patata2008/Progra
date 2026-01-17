#include <bits/stdc++.h>
#include "queso.h"
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}



int encontrar_C(int N) {
    fast();
    set<int> probados;
    auto z = alumnos_notan_cambio(1);
    int ante = N;
    int mini = 1;
    int maxi = N - 1;
    probados.insert(1);
    probados.insert(N);

    if (!alumnos_notan_cambio(N)) return N;
    else {
        for (int i = 0; i < N - 1; i++)
        

    }
    

    return 0;
}