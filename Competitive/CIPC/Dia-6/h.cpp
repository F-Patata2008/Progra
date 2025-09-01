#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

vec <vec <int>> lista;
vec <ll> a;
vec <ll> maxt;
vec <ll> mint;


void dfs(int u, int p) {
    if (p == 0) {
        maxt[u] = a[u-1];
        mint[u] = a[u-1];
    } else {
        maxt[u] = max(a[u-1], a[u-1] - mint[p]);
        mint[u] = min(a[u-1], a[u-1] - maxt[p]);
    }

    for (int v : lista[u]) {
        if (v != p) dfs(v, u);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        a.resize(n);
        lista.assign(n + 1, vec <int> ());
        maxt.assign(n + 1, 0);
        mint.assign(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            lista[a].push_back(b);
            lista[b].push_back(a);
        }

        dfs(1, 0);
        for (int i = 1; i <= n; i++) cout << maxt[i] << (i == n ? "" : " ");
        cout << endl;
    }
    return 0;
}




