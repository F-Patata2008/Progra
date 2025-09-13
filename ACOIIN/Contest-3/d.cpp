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

    ll sA = 0;
    ll sM = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 1) {
            sM = max(sM, sA);
            sA = 0;
        }
        else sA += a[i];
    }
    sM = max(sM, sA);
    cout << sM << endl;

    return 0;
}

