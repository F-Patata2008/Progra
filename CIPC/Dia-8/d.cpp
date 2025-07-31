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
        map <int, ll> comt;
        
        vec <int> a(n);
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            comt[a - i]++;
        }

        ll sum = 0;
        
        for (auto const& pai :comt ) {
            if (pai.second > 1) sum += pai.second * (pai.second - 1) / 2;
        }

        cout << sum << endl;
    }
    return 0;
}

