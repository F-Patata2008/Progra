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
        int n, m;
        cin >> n >> m;

        vec<str> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[ i ];

        int sum = 0;
        int best = INT_MAX;
        int a, b;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                sum = 0;
                for (int k = 0; k < m; k++) {
                    sum += abs((s[ i ][ k ] - 'a') - (s[ j ][ k ] - 'a'));
                }
                best = min(best, sum);
            }
        }
        cout << best << "\n";
    }
    cout << endl;
    return 0;
}
