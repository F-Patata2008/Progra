#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int l, r;
    cin >> l >> r;
    int m = max(l,r);
    if ((l+r)==0) cout << "Not a moose" << "\n";
    else if (l == r) cout << "Even " << 2*l << "\n";
    else cout << "Odd " << 2*m << "\n";
    return 0;
}
