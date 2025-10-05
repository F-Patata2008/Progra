#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n1, n2, k; cin >> n1 >> n2 >> k;
    bool c1 = 2 * n1 >= k;
    bool c2 = 2 * n2 >= k;
    cout << (c1 == c2 ? "SI" : "NO") << endl;
    return 0;
}