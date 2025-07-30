#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vec <vec <int>> grilla(n, vec <int> (m, 0));
        int ka = 1;
        int cont = 0;
        
        if (k % 2 == 0) {
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    for (int j = 0; j < m; j++) {
                        grilla[i][j] = ka;
                        ka++;
                        if (ka > k) {
                            ka = 1;
                        }
                    }
                }
                else  {
                    for (int  j = m-1; j >= 0; j--) {
                        grilla[i][j] = ka;
                        ka++;
                        if (ka > k) {
                            ka = 1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grilla[i][j] << " ";
            }
            cout << "\n";
        }
        cout << endl;

    }
    return 0;
}
