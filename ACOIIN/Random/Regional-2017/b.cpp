#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t, pt, rt;
    int c, pc, rc;

    cin >> t >> pt >> rt;
    cin >> c >> pc >> rc;

    if (t == c) cout << 0 <<endl;
    else if (t < c) {
        cout << min((c - t) * pt, (c - t) * rc) << endl;
    }
    else if (t > c) {
        cout << min((t - c) * pc, (t - c) * rt) << endl;
    }

    return 0;
}
