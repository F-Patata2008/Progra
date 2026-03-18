#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    if (n < m) cout << 0 << endl;
    else {
        int dias = n - m;
        dias /= p;

        cout << 1 + dias << endl;

    }

    return 0;
}
