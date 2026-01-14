#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, k;
    cin >> n >> k;

    set<int> cola;
    queue<int> pantalla;

    for (int i = 0; i < n; i++) {
        int act;
        cin >> act;

        if (cola.find(act) != cola.end()) continue;
        else {
            if (pantalla.size() == k) {
                cola.erase(pantalla.front());
                pantalla.pop();
                pantalla.push(act);
                cola.insert(act);
            }
            else {
                pantalla.push(act);
                cola.insert(act);
            }
        }

    }
    vec<int> resp;
    k = pantalla.size();
    cout << pantalla.size() << endl;
    while (!pantalla.empty()) {
        resp.push_back(pantalla.front());
        pantalla.pop();
    }
    for (int i = k - 1; i >= 0; i--) cout << resp[i] << " ";
    cout << endl;

    return 0;
}
