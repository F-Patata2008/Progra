#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vec <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vec <vec <int>> lista(n);

        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            lista[a].push_back(b);
            lista[b].push_back(a);
        }
    }
    return 0;
}

// Adjacency list to represent the tree
std::vector<std::vector<int>> adj;
// Vector to store danger values
std::vector<ll> a;
// Vectors to store the DP results
std::vector<ll> max_threat;
std::vector<ll> min_threat;

// The DFS function to perform the dynamic programming calculation
void dfs(int u, int p) {
    // Base case: For the root (p == 0), the threat values are just its own danger value.
    if (p == 0) {
        max_threat[u] = a[u-1];
        min_threat[u] = a[u-1];
    } else {
        // Recursive step: Calculate threat values for u based on its parent p.
        // The max threat for u is either a[u] itself, or a[u] minus the minimum path sum from its parent.
        max_threat[u] = std::max(a[u-1], a[u-1] - min_threat[p]);
        // The min threat for u is either a[u] itself, or a[u] minus the maximum path sum from its parent.
        min_threat[u] = std::min(a[u-1], a[u-1] - max_threat[p]);
    }

    // Continue the traversal for all children of u.
    for (int v : adj[u]) {
        // Ensure we don't go back up to the parent.
        if (v != p) {
            dfs(v, u);
        }
    }
}

void solve() {
    int n;
    std::cin >> n;

    // Resize data structures for the current test case.
    // Using n+1 for 1-based indexing to match problem statement.
    a.resize(n);
    adj.assign(n + 1, std::vector<int>());
    max_threat.assign(n + 1, 0);
    min_threat.assign(n + 1, 0);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Start the DFS from the root (vertex 1). The parent of the root is marked as 0.
    dfs(1, 0);

    // Output the final answers (the max_threat for each vertex).
    for (int i = 1; i <= n; i++) {
        std::cout << max_threat[i] << (i == n ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
