#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int t;
    cin >> t;
    while (t--) {
        int Ncaras;
        cin >> Ncaras;

        vector<int> caras(Ncaras/2);
        set<int> cara;
        for (int i = 0; i < Ncaras/2; i++) {
            int ussr;
            cin >> ussr;
            caras[i] = ussr;
            cara.insert(ussr);
        }

        sort(caras.begin(), caras.end());


        bool flag = true;
        for (int i = 0; i < Ncaras/2; i++) {
            if (caras[i] == cara.find(Ncaras+1-caras[i])) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "SI" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}