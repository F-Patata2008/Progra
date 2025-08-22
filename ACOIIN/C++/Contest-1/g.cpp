#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;

    map <str, int> equipos;
    vec <str> p;
    for (int i = 0; i < n; i++) {
        str ussr;
        cin >> ussr;
        auto it = equipos.find(ussr);
        if (it == equipos.end()) {
            equipos[ussr] = 0;
            p.push_back(ussr);
        }
        else equipos[ussr]++;
    }
    int mayor = -1e9;
    str out;
    for (str a : p) {
        if (equipos[a] > mayor) {
            mayor = equipos[a];
            out = a;
        }
    }
    cout << out << endl;
    
    return 0;
}
