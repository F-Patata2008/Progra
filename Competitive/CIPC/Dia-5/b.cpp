#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, n;
        cin >> a >> b >> n;

        int sum = 0;
        while (a <= n || b <= n) {
            if (a < b) {
                a += b;
                sum++;
            }
            else {
                b += a;
                sum++;
            }
        }
        cout << sum-1 << endl;
    }
    return 0;
}


