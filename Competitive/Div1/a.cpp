#include <bits/stdc++.h>
#include <climits>
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

        vec<int> a(n);
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
            cin >> a[ i ];

        if (n % 2 == 1)
            cout << "NO\n";
        else {

            for (int i = 0; i < n; i += 2) {
                maxi = max(a[ i + 1 ], maxi);
                mini = min(a[ i ], mini);
            }
            maxi++;
            mini--;

            int prom = maxi + (mini - maxi) / 2;
            bool b = 1;
            for (int i = 0; i < n; i += 2) {
                if (a[ i ] - 1 <= a[ i + 1 ]) {
                    cout << "NO\n";
                    b = 0;
                    break;
                }
                if (prom == a[ i ] || prom == a[ i + 1 ]) {
                    cout << "NO\n";
                    b = 0;
                    break;
                }
            }
            if (b)
                cout << "YES\n";
        }
    }
    cout << endl;
    return 0;
}
