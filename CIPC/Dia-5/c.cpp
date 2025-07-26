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
        vec <char> ms;

        int con = 1;
        if (size(ussr) == 1) cout << "NO";

        else {
            for (int i = 0; i < size(ussr)-1; i++) if (ussr[i] == ussr[i + 1]) con++;

            if (con == size(ussr)) cout << "NO";
            else {
                cout << "YES\n";
                for (int i = 0; i < size(ussr);) {
                    if (i == size(ussr) - 1) {
                        cout << ussr[i];
                        i++;
                    }
                    else if (ussr[i] != ussr[i + 1]) {
                        cout << ussr[i + 1] << ussr[i];
                        i += 2;
                    }
                    else {
                        cout << ussr[i];
                        i++;
                    }
                }

            }
        }
        cout << endl;
    }
    return 0;
}
