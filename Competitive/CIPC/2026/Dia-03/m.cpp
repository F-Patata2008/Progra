#include <bits/stdc++.h>
#include <functional>
#include <utility>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;


        multimap<int, pair<int, int>, greater<int>> vids;
        vec<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[ i ];
        for (int i = 0; i < n; i++)
            cin >> b[ i ];


        for (int i = 0; i < n; i++)
            vids.insert({b[ i ], make_pair(a[ i ] + i, i)});


        bool si = 1;
        for (auto it = vids.begin(); it != vids.end(); it++) {
            if (q - it->second.first >= 0) {
                cout << it->second.second + 1 << "\n";
                si = 0;
                break;
            }
        }
        if (si)
            cout << -1 << "\n";
    }
    cout << endl;

    return 0;
}
