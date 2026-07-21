#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        // n filas
        // m cols

        vec<vec<int>> grilla (n, vec<int>(m, 0));

        bool alt = 0;
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < m; j += 2) {
                if (alt) {
                    grilla[i][j] = 1;
                    grilla[i + 1][j] = 0;
                    grilla[i][j + 1] = 0;
                    grilla[i + 1][j + 1] = 1;
                    alt = 0;
                }
                else {
                    grilla[i][j] = 0;
                    grilla[i + 1][j] = 1;
                    grilla[i][j + 1] = 1;
                    grilla[i + 1][j + 1] = 0;
                    alt = 1;
                }

            }
            int chek = m / 2;
            if (chek % 2 == 0) {
                if (alt) alt = 0;
                else alt = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grilla[i][j] << " ";
            }
            cout << "\n";
        }
        cout << endl;

    }
    return 0;
}
