#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int reuniones;
    cin  >> reuniones;
    int cant = 1;

    vector <pair<int, int>> Reuniones(reuniones);

    for  (int i = 0; i < reuniones; i++) {
        cin >> Reuniones[i].first;
        cin >> Reuniones[i].second;
    }

    for  (int i = 0; i < reuniones-1; i++) {
        if ((Reuniones[i].second) >  Reuniones[i+1].first) {
            cant++;
        }
    }

    cout  << cant << endl;
    return 0;
}