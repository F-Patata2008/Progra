#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int w, A, n;
    cin >> w >> A >> n;

    map<int, int> h, c;
    map<int, int> v;
    while (n--) {
        char z;
        cin >> z;
        if (z == 'C') {
            ll t, a, p;
            cin >> t >> a >> p;
            c[ p ] = a;
            h[ p ] = t;

        } else {
            ll t, p, m;
            cin >> t >> p >> m;
            if (t - h[ p ] <= w)
                v[ c[ p ] - 1 ] += m;
            else
                v[ c[ p ] - 1 ] += 0;
        }
    }
    for (int i = 0; i < A; i++)
        cout << v[ i ] << "\n";
    cout << endl;

    return 0;
}
