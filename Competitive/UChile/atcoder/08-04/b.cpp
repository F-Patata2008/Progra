#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, m;
    cin >> n >> m;

    vec <vec<int>> fotos (m, vec <int> (n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> fotos[i][j];
        }
    }

    map <int, set<int>> Parejas;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            int x, y;
            x = min(fotos[i][j], fotos[i][j + 1]);
            y = max(fotos[i][j], fotos[i][j + 1]);

            Parejas[x].insert(y);
        }
    }
    int total = (n * (n - 1)) / 2 ;
    int webos = 0;
    for (int i = 1; i < n; i++) {
        set<int> par = Parejas[i];
        for (int x : par) webos++;
    }

    cout << total - webos << endl;
    return 0;
}
