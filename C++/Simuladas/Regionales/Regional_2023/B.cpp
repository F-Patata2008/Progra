#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p, r;
        cin >> p >> r;

        vector <int> puntos(p);
        vector <int> jugadas(p);
        vector <vector<int>> rondas(r);

        for  (int i = 1; i <= r; i++) {
            for (int j = 1; j <= p; j++) {
                cin >> jugadas[j-1];
            }
            rondas[i - 1] = jugadas;
        }


        for (int i = 0; i < r; i++) {
            for (int j = 0; j < p;  j++) {
                if  (rondas[i][j] == 1) {}
            }
        }
    }
    return 0;
}