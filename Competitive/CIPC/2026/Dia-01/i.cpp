#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector


int main() {

    vec<ll> memo(1e7);

    memo[ 0 ] = 2;
    int sum = 5;

    for (int i = 1; i < 1e7; i++) {
        memo[ i ] = memo[ i - 1 ] + sum;
        sum += 3;
    }


    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        sum = 0;
        while (n >= 2) {
            sum++;
            auto it = lower_bound(memo.begin(), memo.end(), n);
            if (*it > n)
                --it;
            n -= *it;
        }

        cout << sum << endl;
    }
    return 0;
}
