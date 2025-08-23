#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    vec <int> fila(n);
    queue <int> par;
    queue <int> inpar;
    
    for (int i = 0; i < n; i++) {
        cin >> fila[i];
    }

    for (int i = 0; i < n; i++) {
        if (fila[i] % 2 == 0) {
            par.push(i + 1);
        }
        else inpar.push(i + 1);
    }

    while (!par.empty()) {
        cout << par.front() << " ";
        par.pop();
    }
    while (!inpar.empty()) {
        cout << inpar.front() << " ";
        inpar.pop();
    }
    cout << endl;
    return 0;
}
