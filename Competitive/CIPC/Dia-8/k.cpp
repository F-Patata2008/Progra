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

        vec <vec <int>> grilla(n, vec <int> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> grilla[i][j];
        }
        
        //ll sum = 0;
        //for (int i = 1; i < 2 * n + 1; i++) sum += (ll) i;
        ll sum = (ll) n * (2 * n +1);

        vec <int> out(2 * n + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out[i + j + 2] = grilla[i][j];
                //sum -= (ll) grilla[i][j];
            }
            
        }
        for (int i = 1; i <= 2 * n; i++) {
            sum -= (ll) out[i];
        }


        out[1] = sum;
        for (int i = 1; i <= 2 * n; i++) cout << out[i] << (i == 2 * n ? "" : " ");
        cout << endl << endl;
    }
    return 0;
}
