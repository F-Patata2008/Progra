#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        cout << (ll) ceil(sqrtl(n)) - 1 << "\n";
    }
    cout << endl;
    return 0;
}
