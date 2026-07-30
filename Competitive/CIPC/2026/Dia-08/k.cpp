#include <bits/stdc++.h>
#include <ios>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        if (x == 1)
            cout << 3;
        else {
            if ((x & ~(1 << (__builtin_ctz(x) + 1))) == 0) {
                cout << (x | 1) << "\n";
            } else {
                cout << (0 ^ (1 << (__builtin_ctz(x) + 1))) << "\n";
            }
        }
    }
    cout << endl;
    return 0;
}
