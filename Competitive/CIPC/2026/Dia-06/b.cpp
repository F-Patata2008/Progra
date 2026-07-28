#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m, r, c;
        cin >> n >> m >> r >> c;

        ll cont = 0;

        cont += (m - c);

        cont += (m - 1) * (n - r);

        cont += (n - r) * (m);


        cout << cont << endl;
    }
    return 0;
}
