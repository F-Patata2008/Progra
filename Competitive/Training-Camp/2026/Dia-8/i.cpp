#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <queue>
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

        vec<int> a(n, -1);
        for (int i = 0; i < n; i++) cin >> a[i];

        vec<int> pares;
        int impares = 0;

        ll impar = INT_MIN;
        for (int  i = 0; i < n; i++) {
            if (a[i] % 2 == 0) pares.push_back(a[i]);
            else {
                impar = max(impar, (ll) a[i]);
                impares++;
            }
        }
        if (pares.size() == n || impares == n) cout << 0 << endl;
        else {
            ll sum  = pares.size();
            sort(pares.begin(), pares.end());

            for(auto act : pares) {
                if (impar > act) impar += act;
                else {
                    sum++;
                    break;
                }
            }
            cout << sum << endl;
        }
        cout << endl;

    }
    return 0;
}
