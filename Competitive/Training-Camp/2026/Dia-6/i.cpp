#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int sum = 0;
vec<vec<int>> lista;
vec<int> portales;

void dfs(int nodo_act) {
    sum++;

}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    lista.assign(n, vec<int> ());
    portales.assign(n, -1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        lista[a].push_back(b);
        lista[b].push_back(a);
    }
    for (int i = 0; i < n; i++) cin >> portales[i];

    if (portales[0] == 1) {
        cout << 0 << endl;
        return 0;
    }
    

    dfs(1);
    cout << sum << endl;
    return 0;
}
