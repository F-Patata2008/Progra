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

        int cont = 1;
        int sum = 0;
        int s = -1;
        for (int i = 0; i < n - 1; i++) {
            sum += abs(a[ i ] - a[ i + 1 ]);
            if (s == 1 && a[ i ] > a[ i + 1 ]) {
                cont++;
                s = 0;
            }

            else if (s == 0 && a[ i ] < a[ i + 1 ]) {
                cont++;
                s = 1;
            }

            if (a[ i ] < a[ i + 1 ])
                s = 1;

            else if (a[ i ] > a[ i + 1 ])
                s = 0;
        }
        if (sum == 0)
            cout << 1 << "\n";
        else
            cout << cont + 1 << "\n";
    }
    cout << endl;
    return 0;
}
