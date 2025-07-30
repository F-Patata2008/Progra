#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n = 8;
        vec <str> grilla(n);

        for (int i = 0; i < n; i++) {
            cin >> grilla[i];
        }
        bool azul = 1;

       for (str ussr : grilla) {
            if (ussr == "RRRRRRRR") azul = false;
        }
        if (azul) cout << "B\n";
        else cout << "R\n";
        cout << endl;
    }
    return 0;
}
