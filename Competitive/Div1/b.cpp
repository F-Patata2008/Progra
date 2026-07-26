#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        if (k == n - 1) {
            cout << -1 << '\n';
            continue;
        }

        int changes = (n - 1) - k;
        string s;

        for (int i = 0; i <= changes; i++) {
            s.push_back((i % 2 == 0) ? '0' : '1');
        }

        while ((int) s.size() < n)
            s.push_back(s.back());

        cout << s << '\n';
    }

    return 0;
}
