#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    ll n, c ,g;
    cin >> n >> c >> g;
    bool jugar= false;


    for (ll  i = 1; i < n+1; i++) {
        if (jugar) break;

        for (ll j = 1; j < n+1; j++) {
            if ((c * i) == (g * j)) {
                jugar = true;
                break;
            }
        }
    }

    if  (jugar) {
        cout << "SI" << endl;
    }
    else if (jugar == false) {
        cout << "NO" << endl;
    }
    return 0;
}