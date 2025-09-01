#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a ,b;
        cin >> a >> b;
        int n = 8;

        if (a == b) n = 4;
        
        vec <pair <int, int>> posR(n);
        vec <pair <int, int>> posD(n);
        

        int xR, yR;
        int xD, yD;

        cin >> xR >> yR;
        cin >> xD >> yD;
        int cont = 0;

        if (a == b) {
            posR[0].first = xR + a;
            posR[0].second = yR + a;
            posR[1].first = xR + a;
            posR[1].second = yR - a;
            posR[2].first = xR - a;
            posR[2].second = yR + a;
            posR[3].first = xR - a;
            posR[3].second = yR - a;

            posD[0].first = xD + a;
            posD[0].second = yD + a;
            posD[1].first = xD + a;
            posD[1].second = yD - a;
            posD[2].first = xD - a;
            posD[2].second = yD + a;
            posD[3].first = xD - a;
            posD[3].second = yD - a;
        }


        else {
            posR[0].first = xR + a;
            posR[0].second = yR + b;
            posR[1].first = xR + a;
            posR[1].second = yR - b;
            posR[2].first = xR - a;
            posR[2].second = yR + b;
            posR[3].first = xR - a;
            posR[3].second = yR - b;
            posR[4].first = xR + b;
            posR[4].second = yR + a;
            posR[5].first = xR + b;
            posR[5].second = yR - a;
            posR[6].first = xR - b;
            posR[6].second = yR + a;
            posR[7].first = xR - b;
            posR[7].second = yR - a;

            posD[0].first = xD + a;
            posD[0].second = yD + b;
            posD[1].first = xD + a;
            posD[1].second = yD - b;
            posD[2].first = xD - a;
            posD[2].second = yD + b;
            posD[3].first = xD - a;
            posD[3].second = yD - b;
            posD[4].first = xD + b;
            posD[4].second = yD + a;
            posD[5].first = xD + b;
            posD[5].second = yD - a;
            posD[6].first = xD - b;
            posD[6].second = yD + a;
            posD[7].first = xD - b;
            posD[7].second = yD - a;
        }


        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (posR[i].first == posD[j].first && posR[i].second == posD[j].second) cont++;
            }
        }

        cout << cont << endl;


    }
    return 0;
}
