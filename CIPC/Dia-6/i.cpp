#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define que queue
#define vec vector

int n, m;
vec <vec <int>> lista;
vec <int> dist; //funciona como vec de vistados tmb, al inicializarlo en -1

pair <int, int> BFS (int start) {
    que<int> q;
    dist.assign(n, -1);
    dist[start] = 0;

    q.push(start);
    int farthest = start;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        farthest = u;

        for (int v : lista[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {farthest, dist[farthest]};
}

int main() {
    cin >> n >> m;
    lista.assign(n, vec<int>());

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        lista[u].push_back(v);
        lista[v].push_back(u);
    }
    
    cout << BFS(BFS(0).first).second << endl;
    return 0;
}
