#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        str ussr;
        cin >> ussr;


        vec <int> pos;
        int cont = 0;
        for (int i = 0; i < n; i++) {
            if (ussr[i] == '*') {
                pos.push_back(i);
                cont++;
            }

        }

        if (cont <= 1) cout << 0 << "\n";
        else {
            ll sum = 0;
            int medio = pos[(cont - 1) / 2];
            for (int i = (cont - 1) / 2; i >= 0; i--) {
                sum += (ll) abs(pos[i] - pos[(cont - 1) / 2] + (cont - 1) / 2 - i);
            }
            for (int i = (cont - 1) / 2 + 1; i < pos.size(); i++) {
                sum += (ll) abs(pos[i] - medio - i + (cont - 1) / 2);
            }
            cout << sum << "\n";
        }
        cout << endl;
    }
    return 0;
}
