#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    ll a,b;
    while (cin >> a >> b) {
        ll mx = max(a, b);
        ll mn = min(a, b);
        cout << mx-mn << "\n";
    }
    return 0;
}
