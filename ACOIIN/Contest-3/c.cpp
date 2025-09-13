#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    vec <ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sA = a[0];
    ll sM = a[0];

    for (int i = 1; i < n; i++) {
        sA = max(a[i], a[i] + sA);
        sM = max(sA, sM);
    }

    cout << sM << endl;

    return 0;
}
