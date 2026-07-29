#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vec<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[ i ];

        map<int, int> freq;
        for (auto ai : a)
            freq[ ai ]++;
        vec<int> si;
        for (auto it : freq) {
            if (it.second >= k)
                si.push_back(it.first);
        }
        if (si.size() == 0)
            cout << -1 << "\n";


        else {
            int maxi = -1;
            int izq = si[ 0 ], der = si[ 0 ];

            int L = 0;
            for (int R = 0; R < si.size(); R++) {
                if (R > 0 && si[ R ] != si[ R - 1 ] + 1) {
                    if (si[ R - 1 ] - si[ L ] > maxi) {
                        maxi = si[ R - 1 ] - si[ L ];
                        izq = si[ L ];
                        der = si[ R - 1 ];
                    }
                    L = R;
                }
            }

            if (si.back() - si[ L ] > maxi) {
                izq = si[ L ];
                der = si.back();
            }

            cout << izq << " " << der << "\n";
        }
    }
    cout << endl;
    return 0;
}
