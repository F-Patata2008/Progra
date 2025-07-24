#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector


void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vec<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    std::vector<bool> checks(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] < 2LL * a[i+1]) {
            checks[i] = true;
        } else {
            checks[i] = false;
        }
    }

    int ans = 0;
    int consecutive_true = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        if (checks[i]) {
            consecutive_true++;
        } else {
            consecutive_true = 0;
        }

        if (consecutive_true >= k) {
            ans++;
        }
    }

    std::cout << ans << std::endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solver();
    }
    return 0;
}



