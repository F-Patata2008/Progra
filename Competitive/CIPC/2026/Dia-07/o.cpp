#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            int n, x;
            cin >> n >> x;

            vector<int> a(n), b(n), c(n);
            for (int i = 0; i < n; i++)
                cin >> a[ i ];
            for (int i = 0; i < n; i++)
                cin >> b[ i ];
            for (int i = 0; i < n; i++)
                cin >> c[ i ];

            int sum = 0;

            for (int act : a) {
                if ((act | x) == x) {
                    sum |= act;
                } else {
                    break;
                }
            }

            for (int act : b) {
                if ((act | x) == x) {
                    sum |= act;
                } else {
                    break;
                }
            }

            for (int act : c) {
                if ((act | x) == x) {
                    sum |= act;
                } else {
                    break;
                }
            }

            if (sum == x) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
