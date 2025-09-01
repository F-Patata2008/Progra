#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string


const int max_n = 201, max_m = 201;
    int grilla[max_n][max_m];
    int mem[max_n][max_m];


     int DP (int n, int m) {
        if (m < 0 || n < 0) return 0;
        if (mem[n][m] != 0) return mem[n][m];
        mem[n][m] = min(DP(n - 1, m), DP(n, m - 1)) + grilla[n][m];
        return mem[n][m];
    }




int main() {
    int n,m;
    cin >> n;
    m = n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grilla[i][j];
        }
    }
    cout << DP(n - 1, m - 1) << endl;
    return 0;
}