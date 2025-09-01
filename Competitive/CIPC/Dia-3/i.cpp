#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n ;
        cin >> n;

        vec <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            str ussr;
            cin >> ussr;
            if (ussr.size() != n) {
                cout << "NO\n";
                continue;
            }
            map <int, char> nc;
            map <char, int> cn;
            bool si = true;

            int actN, actC;
            for (int i = 0; i < n; i++) {
                actN = a[i];
                actC = ussr[i];

                if (nc.count(actN)) {
                    if (nc[actN] != actC) {
                        si = 0;
                        break;
                    }
                }

                if (cn.count(actC)) {
                    if (cn[actC] != actN) {
                        si = 0;
                        break;
                    }
                }
                nc[actN] = actC;
                cn[actC] = actN;

            }
            if (si) cout << "YES\n";
            else cout << "NO\n";

        }
        cout << endl;
    }
    return 0;
}
