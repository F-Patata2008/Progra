#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int l, r;
    cin >> r >> l;

    str ussr;
    cin >> ussr;

    l--;
    r--;
    char c;

    while ((l - r) > 0) {
        c = ussr[ l ];
        ussr[ l ] = ussr[ r ];
        ussr[ r ] = c;
        l--;
        r++;
    }
    cout << ussr << endl;

    return 0;
}
