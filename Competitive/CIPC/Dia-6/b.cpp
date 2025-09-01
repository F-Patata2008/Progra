#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vec <int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    vec <vec <int>> DP(n + 1, vec<int>(3, INF));
    DP[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        int hoy = a[i - 1];

        DP[i][0] = 1 + min({DP[i - 1][0], DP[i - 1][1], DP[i - 1][2]});

        if (hoy == 1 || hoy == 3) DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]);
        

        if (hoy == 2 || hoy == 3) DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]);
    }

    cout << min({DP[n][0], DP[n][1], DP[n][2]}) << endl;




    return 0;
}
