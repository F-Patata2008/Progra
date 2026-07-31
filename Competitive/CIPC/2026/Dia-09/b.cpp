#include <bits/stdc++.h>
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
        for (int i = 0; i < n; i++)
            cin >> a[ i ];

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int cont = 0;

            for (int j = 0; j < n; j++) {
                if (j % 2 == i % 2 && a[ j ] <= a[ i ])
                    cont++;
            }

            int act = a[ i ] + cont;
            maxi = max(maxi, act);
        }

        cout << maxi << "\n";
    }
    return 0;
}
