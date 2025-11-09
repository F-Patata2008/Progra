#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef string str;
#define vec vector

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main () {
    fast();

    int n, m;
    cin >> n >> m;
    str z;
    

    vec <str> Grilla(n);
    str o;
    for (int i = 0; i < n; i++) {
        cin >> o;
        Grilla[i] = o + o;
    }
    z = o + o;
    for (int i = 0; i < m; i++) {
        z[i] = '.';
    }


    int q;
    cin >> q;
    bool si = 0;
    int x, y;
    while (q--) {
        //matriz se define como (fila,columna)
        si = 0;
        cin >> y >> x;

        if (z == Grilla[y]) si = 0;
        else {
            for (int i = x + m; i >= 0; i--) {
                if (Grilla[y][i] != '.') {
                    cout << Grilla[y][i] << endl;
                    si = 1;
                    break;
                }
            }
        }
        if (!si) cout << '.' << endl;
    }


    return 0;
}