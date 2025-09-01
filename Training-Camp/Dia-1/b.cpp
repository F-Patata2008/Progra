#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int sala, profes, veces;
        cin >> sala >> profes >> veces;

        vec<int> PosProfes(profes);
        for (int i = 0; i < profes; i++) {
            cin >> PosProfes[i];
        }
        sort(PosProfes.begin(), PosProfes.end());

        vec<int> PosDavid(veces);
        for (int i = 0; i < veces; i++) {
            cin >> PosDavid[i];
        }

        for (int i = 0; i < veces; i++) {
            int David = PosDavid[i];

            auto r = lower_bound(PosProfes.begin(), PosProfes.end(), David);
            int der = sala+1;
            if(r != PosProfes.end()) der = *r;
            auto l = upper_bound(PosProfes.begin(), PosProfes.end(), David);
            int izq = 0;
            if(l != PosProfes.begin()) izq = *prev(l);


            if( der == sala+1) {
                cout << sala - PosProfes[profes-1] << endl;
            }
            else if (izq == 0) {
                cout << PosProfes[0]-1 << endl;
            }
            else {
                cout << (der- izq)/2 << endl;
            }
        }
        
    }
    return 0;
}