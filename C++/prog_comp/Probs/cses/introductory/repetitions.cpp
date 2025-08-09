#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    str ussr;
    cin >> ussr;

    int cont = 0;
    int maxi = 0;
    for (int i = 0; i < ussr.size() - 1; i++) {
        if (ussr[i] == ussr[i + 1]) {
            cont++;
            if ( cont > maxi) maxi = cont;
        }
        else cont = 0;
    }
    cout << maxi + 1 << endl;
    return 0;
}
