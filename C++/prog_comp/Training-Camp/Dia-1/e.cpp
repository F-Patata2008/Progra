#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vec <int> a(2*n);

        for (int i = 0; i < 2*n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vec<int> copy = a;
        int suminit = a[(2* n)-1];
        
    }
    return 0;
}