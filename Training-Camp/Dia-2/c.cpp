#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

int main() {
    int caballeros, peleas;
    cin >> caballeros >> peleas;

    set<int> Lista;

    for (int i = 0; i < caballeros; i++) {
        Lista.insert(i);
    }

    vec<int> out(caballeros , -1);

    for (int i = 0; i < peleas; i++) {
        int parte, termina, gana;
        cin >> parte >> termina >> gana;
        parte--; termina--; gana--;

        auto it1 = Lista.lower_bound(parte);
        auto it2 = Lista.upper_bound(termina);


        while (it1 != it2) {
            auto sig = next(it1);
            if (*it1 != i) {
                out[*it1] = i;
                Lista.erase(*it1);
            }
            it1 = sig;
        }

    }

    for (int i = 0; i < caballeros; i++) {
        cout << out[i] +1 << endl;
    }




    return 0;
}