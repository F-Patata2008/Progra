#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    ll k;
    cin >> n >> k;

    vec<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[ i ];

    ll cont = 0;

    int l = 0;
    int sum = a[ 0 ];

    for (int r = 1; r < n;) {
        sum += a[ r ];
        if (sum == k) {
            cont++;
            r++;
        }

        else {
            while (sum != k && l < r) {
                sum -= a[ l ];
                l++;
            }
        }
    }
    cout << cont << endl;

    return 0;
}
