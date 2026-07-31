#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    if (!(cin >> n >> x))
        return 0;

    vector<int> a(n);
    bool esta = false;

    for (int i = 0; i < n; i++) {
        cin >> a[ i ];
        if (a[ i ] == x)
            esta = true;
    }

    int ans = 0;

    if (!esta) {
        a.push_back(x);
        ans++;
    }

    sort(a.begin(), a.end());

    while (true) {
        int sz = a.size();
        int med_idx = (sz - 1) / 2;

        if (a[ med_idx ] == x) {
            break;
        }

        if (a[ med_idx ] < x) {
            a.push_back(100005);
        } else {
            a.push_back(1);
        }

        sort(a.begin(), a.end());
        ans++;
    }

    cout << ans << "\n";

    return 0;
}
