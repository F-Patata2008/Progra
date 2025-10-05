#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector <int> Alt(n, -1);
    vector <int> dist(n - 1);

    for (int i = 0; i < n; i++) {
        cin >> Alt[i];
    }
    for (int i = 0; i < n - 1; i++) {
        dist[i] = abs(Alt[i] - Alt[i + 1]);
    }

    for (int i = 0; i < q; i++) {
        int l, r , k;
        cin >> l >> r >> k;
        
        if (k == 1) {
            cout << "SI" << endl;
        }
        else {
            bool act = 1;

            for (int i = min(l, r) - 1; i < max(r, l) - 2; i++) {
                if (dist[i] % k != 0) {
                    act = 0;
                    break;
                }
            }
            if (act) cout << "SI" << endl;
            if (!act) cout << "NO" << endl;
    }

    }


}