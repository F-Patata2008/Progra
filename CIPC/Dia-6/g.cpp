#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int n, m, nodos = 0;

vec <vec <int>> lista;
vec <bool> vis;

void dfs (int z) {
    vis[z] = true;
    nodos++;
    for (int v : lista[z]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    cin >> n >> m;


    if (m != n - 1) cout << "no" << endl;
    else if (n == 1) cout << "yes" << endl;
    else {
        lista.assign(n,vec <int> ());
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            lista[u].push_back(v);
            lista[v].push_back(u);
        }
        vis.assign(n, false);
        
       dfs(0);

        if (nodos == n) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
