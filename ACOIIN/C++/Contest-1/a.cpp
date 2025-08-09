#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

map <char, int> p;

int main() {
    str ussr;
    cin >> ussr;
    int n = ussr.size();
    
    vec <bool> si(5, 0);
    for (int i = 0; i < n; i++) {
        if (si[0] == 0) {
            if (ussr[i] == 'a') si[0] = 1;
        }
        else if (si[0] == 1) {
            if (ussr[i] == 'e') si[1] = 1;
        }
        else if (si[1] == 1) {
            if (ussr[i] == 'i') si[2] = 1;
        }
        else if (si[2] == 1) {
            if (ussr[i] == 'o') si[3] = 1;
        }
        else if (si[3] == 1) {
            if (ussr[i] == 'u') si[4] = 1;
        }
    }
    int cont = 0;
    for (int i = 0; i < 5; i++) {
        if (si[i] == 1) cont++;
    }
    if (cont == 5) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
