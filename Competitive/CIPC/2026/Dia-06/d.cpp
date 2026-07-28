#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;


    vec<int> dp(n);

    dp[ 0 ] = 0;
    dp[ 1 ] = 1;
    for (int jug = 2; jug < n; jug++) {
        dp[ jug ] = max(dp[ jug - 1 ], dp[ jug - 2 ]) + 1;
    }

    cout << dp[ n - 1 ] << endl;

    return 0;
}
