#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;

    int x,y;
    while (t--) {
        cin >> y >> x;

        ll m = max(x,y);
        ll ant = (m-1)*(m-1);

        if (m % 2 == 1) {
            if (x == m) cout << m * m - (y - 1) << endl;
            else cout << ant + x << endl;
        }
        else {
            if (y == m) cout << m * m - (x - 1) << endl;
            else cout << ant + y << endl;
        }
        
    }
    return 0;
}
