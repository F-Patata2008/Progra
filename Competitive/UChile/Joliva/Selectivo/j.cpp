#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, m;
    cin >> n >> m;

    set<int> a, c;

    int cont = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        if (a.find(u) != a.end() && a.find(v) != a.end())
            break;
        if (c.find(u) != c.end() && c.find(v) != c.end())
            break;

        if ((a.find(u) == a.end() && c.find(u) == c.end()) && (a.find(v) == a.end() && c.find(v) == c.end())) {
            a.insert(u);
            c.insert(v);
            cont++;
        } else if (a.find(u) != a.end() && c.find(v) == c.end()) {
            c.insert(v);
            cont++;
        } else if (a.find(u) == a.end() && c.find(v) != c.end()) {
            a.insert(u);
            cont++;
        }
    }

    cout << cont << endl;

    return 0;
}
