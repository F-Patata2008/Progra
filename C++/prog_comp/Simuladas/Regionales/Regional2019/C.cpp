#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int dias;
    int promE;
    cin >> dias  >> promE;


    vector<int> ICPC(dias);
    for (int x = 0; x < dias; x++) {
        cin >> ICPC[x];
    }



    int y_max = 0;
    int pos = -1;
    for (int x = 0; x < dias; x++) {
        int val = 0;
        int promA;
        for  (int y = x; y < dias; y++) {
            //cout << "Vamos en el elemento: " << x << " --- " << y << endl;
            val +=  ICPC[y];
            promA = val / (y+1);
            if  (promA == promE && (val % (y + 1) == 0)) {
                // cout << "Valor: " << val << endl;
                // cout  << "Posicion: " << x << " -- " << y << endl << endl;
                if ((y + 1) > y_max) {
                        pos = x;
                        y_max = (y + 1) - x;
                    }
                }
            }
    }
    cout <<  pos << " " << y_max << endl;
    return 0;
}
