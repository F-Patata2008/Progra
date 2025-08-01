#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, h;
        cin >> n >> h;

        int maxi1 = 0, maxi2 = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            if ( a > maxi1) {
                maxi2 = maxi1;
                maxi1 = a;
            }
            else if ( a > maxi2) maxi2 = a;

            
        }
        if (maxi1 >= h) cout << 1 << endl;
        else {
            int cont = h / (maxi1 + maxi2);
            cont *= 2;
            if (h % (maxi1 + maxi2) != 0) {
                if (maxi1 >= h % (maxi1 + maxi2)) {
                    cont++;
                }
                else cont += 2;
            }
            cout << cont << endl;
        }

    }
    return 0;
}
