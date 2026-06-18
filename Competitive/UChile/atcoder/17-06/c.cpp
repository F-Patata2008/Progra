#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, m;
    cin >> n >> m;

    vec<int> a (n);
    vec<int> b (m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    int mini = INT_MAX;
    int A;
    int ab, ba;
    for (int i = 0; i < n; i++) {
        A = a[i];
        auto busc = lower_bound(b.begin(), b.end(), A);

        ab = abs(A - *busc);
        ba = INT_MAX;
        if (busc != b.begin()) {
            --busc;
            ba = abs(A - *busc);
        }
        mini = min({ab, ba, mini});
    }

    cout << mini << endl;

    return 0;
}
