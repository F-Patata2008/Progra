#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, m;
    cin >> n >> m;

    vec<int> caba(n);
    vec<bool> cab(n, 0);
    int ult;
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--; x--;
        ult = x;
        for (int j = l; j < r; j++) {
            if (j == x) continue;
            else {
                if (!cab[j])
                caba[j] = x;
                cab[j] = 1;
            }
        }
    }
    caba[ult] = 0;

    for (int i = 0; i < n; i++){
        if (i == ult) cout << 0 << " ";
        else cout << caba[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}
