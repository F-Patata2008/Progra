#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, int depth, vector<int> &dist, const vector<vector<int>> &adj, int &far_node) {
    dist[ u ] = depth;

    if (far_node == -1 || dist[ u ] > dist[ far_node ]) {
        far_node = u;
    }

    for (int v : adj[ u ]) {
        if (v != p) {
            dfs(v, u, depth + 1, dist, adj, far_node);
        }
    }
}

int get(int n, const vector<vector<int>> &adj) {
    int nodeA = -1;
    vector<int> distA(n, 0);
    dfs(0, -1, 0, distA, adj, nodeA);

    int nodeB = -1;
    vector<int> distB(n, 0);
    dfs(nodeA, -1, 0, distB, adj, nodeB);

    return distB[ nodeB ];
}

int main() {
    // --- ÁRBOL 1 ---
    int n1;
    cin >> n1;
    vector<vector<int>> adj1(n1);
    for (int i = 0; i < n1 - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj1[ u - 1 ].push_back(v - 1);
        adj1[ v - 1 ].push_back(u - 1);
    }

    // --- ÁRBOL 2 ---
    int n2;
    cin >> n2;
    vector<vector<int>> adj2(n2);
    for (int i = 0; i < n2 - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj2[ u - 1 ].push_back(v - 1);
        adj2[ v - 1 ].push_back(u - 1);
    }

    int d1 = get(n1, adj1);
    int d2 = get(n2, adj2);

    int r1 = (d1 + 1) / 2;
    int r2 = (d2 + 1) / 2;


    cout << max({d1, d2, (d1 + d2) / 2 + 2}) << endl;

    return 0;
}
