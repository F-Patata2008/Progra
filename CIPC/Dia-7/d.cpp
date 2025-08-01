#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector


int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        int out;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                out = (i * max(1, m % k) + j) % k + 1;
                cout << out;

                if(j == m - 1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
