#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int t;
    cin >> t;
    while (t--) {
        int libros;
        cin >> libros;
        int minA = INT_MAX, minB = INT_MAX, minD = INT_MAX;
        bool a =false;
        bool b = false;

        for (int i = 0; i < libros; i++) {
            int a;
            str b;
            cin >> a >> b;
            if (b == "10" ) {
                minA = a;
                if (a < minA) {
                    a = true;
                }
            }
            if (b == "01") {
                minB = a;
                if (a < minB) {
                    b = true;
                }
            }
            if (b == "11") {
                minD = a;
                if (a < minD) {
                    a = true;
                    b = true;
                }
            }

        }
        if (!a || !b ) {
            cout << -1 << endl;
        }

        else {
            if (minA + minB < minD) {
                cout << minA + minB << endl;
            }
            if (minD < minA + minB) {
                cout << minD << endl;
            }
        }


        
    }
    return 0;
}