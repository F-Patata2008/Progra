#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

ll C[65][65];

void combi() {
    for (int i = 0; i <= 60; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}





int main() {
    int t;
    cin >> t;
    combi();

    while (t--) {
        int n, k;
        cin >> n >> k;


        int largo = 0;
        ll copia = n;
        while ((copia & 1) == 0) {
            copia>>=1;
            largo++;
        }

        ll gana = 0;
        if (largo + 1 <= k) gana++;

        for (int i = 0; i < largo; i++) {
            ll maxi = k - i - 1;
            for (int j = 0; j <= i; j++) {
                if (j <= maxi) gana += C[i][j];
            }

        }


        cout << n - gana << endl;
    }



    cout << endl;
    return 0;
}
