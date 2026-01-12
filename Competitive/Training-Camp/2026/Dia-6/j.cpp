#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    cout << "1 1 " << n << endl; // Query tipo 1: suma original
    ll sum_p_total;
    cin >> sum_p_total;

    cout << "2 1 " << n << endl; // Query tipo 2: suma modificada
    ll sum_a_total;
    cin >> sum_a_total;

    int length = sum_a_total - sum_p_total;

    int low = 1, high = n;
    int l = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        cout << "1 1 " << mid << endl;
        ll s1;
        cin >> s1;

        cout << "2 1 " << mid << endl;
        ll s2;
        cin >> s2;

        if (s1 != s2) {
            l = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    int r = l + length - 1;

    cout << "! " << l << " " << r << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
