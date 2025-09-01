#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int t;
    cin >> t;
    while (t--) {
        int reglas, cantcontras;
        cin >> reglas >> cantcontras;
        vector<pair<char,char>> ListaReglas;

        char de, A;
        for (int x = 0; x < reglas; x++) {
            pair<char,char> regla_actual;
            cin >> de >> A;
            regla_actual.first = A;
            regla_actual.second = de;
            ListaReglas.push_back(regla_actual);
        }
        reverse(ListaReglas.begin(), ListaReglas.end());
        

        str ussr;
        str outys;
        for (int x = 0; x < cantcontras; x++) {
            cin >> ussr;
            outys == ussr;
            str outys1;
            for (int y = 0; y < sizeof(ListaReglas); y++) {
                outys1 = "";
                for (char z : outys) {
                    if (z == ListaReglas[y].first) {
                        outys1.push_back(ListaReglas[y].second);
                    }
                    else {
                        outys1.push_back(z);
                    }
                }
                outys = outys1;
            }
            outys = outys1;
            cout << outys << endl;
        }
    }
    return 0;
}