#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        vec <str> soduku(9);
        vec <vec <int>> sodoku(9, vec <int> (9, 0));
        for (int i = 0; i < 9; i++) cin >> soduku[i];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (soduku[i][j] == '1') sodoku[i][j] = 2;
                else sodoku[i][j] = soduku[i][j] - '0';
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sodoku[i][j];
            }
            cout << "\n";
        }
        cout << endl;
    }
    return 0;
}
