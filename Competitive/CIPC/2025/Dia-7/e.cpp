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
        vec <int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
        bool si = 1;
        for (int i = 1; i < n; i++) {
            if (a[i-1] == a[i]) si = 0;
        }

        if (si) cout << "YES\n";
        else cout << "NO\n";
        cout << endl;
    }
    return 0;
}
