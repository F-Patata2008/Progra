#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {

    string s;
    cin >> s;

    int n = (int) s.size();
    int ans = -1;

    int firstV = -1;

    for (int i = 0; i < n; i++) {
        if (s[ i ] == 'P') {
            if (firstV != -1) {
                ans = max(ans, i - firstV);
            }
            firstV = -1;
        } else {
            if (s[ i ] == 'V' && firstV == -1) {
                firstV = i;
            }
        }
    }

    cout << ans + 1 << "\n";
    return 0;
}
