#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXA = 1000005;
ll h[ MAXA ];

void init_hash() {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 1; i < MAXA; i++) {
        h[ i ] = rng();
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init_hash();

    int t;
    if (cin >> t) {
        while (t--) {
            int n, q;
            cin >> n >> q;

            vector<ll> pref(n + 1, 0);
            for (int i = 1; i <= n; i++) {
                int x;
                cin >> x;
                pref[ i ] = pref[ i - 1 ] ^ h[ x ];
            }

            while (q--) {
                int l, r;
                cin >> l >> r;

                if ((pref[ r ] ^ pref[ l - 1 ]) == 0) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}
