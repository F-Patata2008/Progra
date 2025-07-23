#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int Dias, C,T;
    cin >> Dias >> C >> T;
    char a,b, c, d;
    for (int i = 0; i < Dias; i++) {
        cin >> a >> b;
        if (a == 'Y') {
            c = 'Y';
            C--; T++;
        }
        if (a == 'N' && T > 0) c = 'N';
        if (a == 'N' && T == 0) {
            c = 'Y';
            C--; T++;
        }



        if (b == 'Y') {
            d = 'Y';
            T--; C++;
        }
        if (b == 'N' && C > 0) d = 'N';
        if (b == 'N' && C == 0) {
            d = 'Y';
            C++; T--;
        }
        cout << c << " " << d << "\n";
    }
    return 0;
}
