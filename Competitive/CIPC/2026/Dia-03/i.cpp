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


        int u, v;
        map<int, int> nodos;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            nodos[ u ]++;
            nodos[ v ]++;
        }

        int con = 0;
        map<int, int> cont;
        for (int i = 1; i <= n; i++) {
            if (nodos[ i ] > 1)
                cont[ nodos[ i ] ]++;
        }


        if (cont.size() == 1)
            cout << cont.begin()->first << " " << cont.begin()->first - 1 << "\n";
        else {
            int x, y;
            for (auto xy : cont) {
                if (xy.second == 1)
                    x = xy.first;
                else
                    y = xy.first;
            }
            cout << x << " " << y - 1 << "\n";
        }
    }
    cout << endl;
    return 0;
}
