#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXR = 2024;
ll dp[ MAXR ][ MAXR ];
ll ans[ 2000005 ];


int main() {
    ll val = 1;
    dp[ 0 ][ 0 ] = 0;

    for (int r = 1; r < MAXR; r++) {

        for (int c = 1; c <= r; c++) {
            if (val > 2000000)
                break;
            if (r >= 2)
                dp[ r ][ c ] = (val * val) + dp[ r - 1 ][ c - 1 ] + dp[ r - 1 ][ c ] - dp[ r - 2 ][ c - 1 ];
            else
                dp[ r ][ c ] = (val * val) + dp[ r - 1 ][ c - 1 ] + dp[ r - 1 ][ c ];
            ans[ val ] = dp[ r ][ c ];
            val++;
        }
    }


    int t;
    cin >> t;

    int n;

    while (t--) {
        cin >> n;
        cout << ans[ n ] << "\n";
    }
    return 0;
}
