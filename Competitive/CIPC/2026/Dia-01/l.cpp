#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; // filas
        cin >> n;

        vec<str> fila(n);
        for (int i = 0; i < n; i++)
            cin >> fila[ i ];

        // 4 columnas

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                if (fila[ i ][ j ] == '#') {
                    cout << j + 1 << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
