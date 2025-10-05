#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> alturas(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> alturas[i];
    }
    unordered_map<int, int> solved_queries;
    sort(alturas.begin(), alturas.end());
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        if (solved_queries[v] != -1) {
            cout << solved_queries[v] << endl;
            continue;
        }
        auto it = lower_bound(alturas.begin(), alturas.end(), v);
        int sol = -(alturas.begin() - it);
        solved_queries[v] = sol;
        cout << sol << endl;
    }
    return 0;
}