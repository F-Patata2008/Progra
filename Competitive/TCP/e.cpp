#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> sv(n);
    for (int i = 0; i < n; i++) {
        cin >> sv[i];
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (sv[x][y] == 'T') {
                // check derecha
                if (y < n - 2) {
                    if (sv[x][y + 1] == 'C' && sv[x][y + 2] == 'P') {
                        cout << "SI" << endl;
                        return 0;
                    }
                }
                // check abajo
                if (x < n - 2) {
                    if (sv[x + 1][y] == 'C' && sv[x + 2][y] == 'P') {
                        cout << "SI" << endl;
                        return 0;
                    }
                }
                // check diagonal
                if (x < n - 2 && y < n - 2) {
                    if (sv[x + 1][y + 1] == 'C' && sv[x + 2][y + 2] == 'P') {
                        cout << "SI" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}