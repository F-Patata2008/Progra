#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vec<int> d(n);
    int ussr;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());

    int cont = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && d[j]-d[i]<=k) j++;
        cont = max(j-i,cont);
    }
    cout << cont << "\n";

    
    return 0;
}
