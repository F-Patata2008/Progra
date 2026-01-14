#include <bits/stdc++.h>
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
        int cero,uno;
        cero = 0;
        uno = 0;

        for (char i : ussr) {
            if (i == '0') cero++;
            if (i == '1') uno++;
        }

        int sum = 0;
        for (char i : ussr) {
            if (i == '0') {
                if (uno > 0) {
                    uno--;
                    sum++;
                }
                else break;
            }
            else {
                if (cero > 0) {
                    cero--;
                    sum++;
                }
                else break;
            }

        }
        cout << ussr.size()-sum << "\n";

    }
    return 0;
}
