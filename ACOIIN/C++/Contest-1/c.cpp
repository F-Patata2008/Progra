#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        str ussr;
        cin >> ussr;

        int cont = 0;
        bool si = 1;

        for (int i = 0; i < ussr.size(); i++) {
            if (ussr[i] != '0' and ussr[i] != '1') {
                si = 0;
                break;
            }
        }
        for (char z : ussr) {
            if (z == '1') cont++;
        }


        if (si && cont % 2 == 0) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}
