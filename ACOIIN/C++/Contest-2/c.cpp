#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int meta;
    cin >> meta;

    int sum = 0;
    int x;

    int cont = 0;
    int ou;
    bool out = 0;

    while (cin >> x) {
        cont++;
        sum += x;
        if (sum >= meta) {
            ou = cont;
            out  = 1;
            break;
        }
    }
    if (out) cout << "Meta alcanzada en " << ou << " minutos" << endl;
    else cout << "No se alcanzó la meta" << endl;

    return 0;
}
