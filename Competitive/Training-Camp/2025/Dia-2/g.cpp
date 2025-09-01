#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

int main() {
    int libros, tiempo;
    cin >> libros >> tiempo;
    int final;
    vec<int> tiempos(libros);

    for (int i = 0; i < libros; i++) {
        cin >> tiempos[i];
    }

    int best = 0;

    int sum = 0;
    int r = 0;
    for(int l = 0; l < libros; l++){
        
        while(r < libros && sum + tiempos[r] <= tiempo){
            sum += tiempos[r];
            r++;
        }

        best = max(best,  r-l);

        sum -= tiempos[l];
    }

    cout << best << endl;






    return 0;
}