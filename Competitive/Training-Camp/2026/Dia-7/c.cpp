#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    str ussr;
    cin >> ussr;
    int n = ussr.size();

    vec<bool> letra(26, 0);
    vec<int> posi[26];
    for (int i = 0; i < n; i++) posi[ussr[i] - 'a'].push_back(i);

    vec<int> distancias(n, INF);
    distancias[0] = 0;

    priority_queue<pair<int, int>, vec<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});


    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > distancias[u]) continue;
        if (u + 1 < n) {
            if (distancias[u] + 1 < distancias[u + 1]) {
                distancias[u + 1] = distancias[u] + 1;
                pq.push({distancias[u + 1], u + 1});
            }
        }

        int posA = ussr[u] - 'a';
        if (!letra[posA]) {
            for (int v : posi[posA]) {
                if ( v > u && distancias[u] < distancias[v]) {
                    distancias[v] = distancias[u];
                    pq.push({distancias[v], v});
                }
            }

            letra[posA] = 1;
            posi[posA].clear();
        }
    }
    cout << distancias[n - 1] << endl;

    return 0;
}
