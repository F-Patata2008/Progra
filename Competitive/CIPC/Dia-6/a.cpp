#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define que queue
#define pqu priority_queue
#define vec vector

const ll INF = 1e18;
int n, m;
vec <vec <pair <int, int>>> lista;
vec <ll> dist;
vec <int> papo;

int main() {
    cin >> n >> m;
    lista.assign(n + 1, vec <pair <int, int>>());
    dist.assign(n + 1, INF);
    papo.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        lista[u].push_back({v, w});
        lista[v].push_back({u, w});
    }

    pqu <pair <ll, int>, vec <pair <ll, int>>, greater <pair <ll, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;
        if (u == n) break;

        for (auto& edge : lista[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                papo[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF) cout << -1 << endl;
    else {
        vec<int> path;
        for (int curr = n; curr != 0; curr = papo[curr]) path.push_back(curr);
        

        reverse(path.begin(), path.end());
        for (size_t i = 0; i < path.size(); i++) cout << path[i] << (i == path.size() - 1 ? "" : " ");
        
        cout << endl;
    }

    return 0;
}
