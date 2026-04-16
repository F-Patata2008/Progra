#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, q;
    cin >> n >> q;


    vec <set<int>> cajas (n);
    int act;

    for (int i = 0; i < n; i++) {
        cin >> act;
        cajas[i].insert(act);
    }

    int a, b;
    while (q--) {
        cin >> a >> b;
        a--; b--;
        cajas[b].merge(cajas[a]);
        cajas[a].clear();

        cout << cajas[b].size() << endl;
    }

    cout << endl;

    return 0;
}
