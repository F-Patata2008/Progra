#include <algorithm>
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

        vec <int> a(1001, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x] = i+1;
        }
        int out = -1;
        for (int i = 0; i <= 1000; i++) {
            if (a[i] == 0) continue;
            for (int j = i; j <= 1000; j++) {
                if (a[j] == 0) continue;
                if (gcd(i, j) == 1) out = max(a[i] + a[j] , out);
            }
        }
        cout << out << endl;
    }
    return 0;
}
