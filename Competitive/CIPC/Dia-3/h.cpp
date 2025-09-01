#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a + b == c) cout << "YES\n";
        else if (b + c == a) cout << "YES\n";
        else if (c + a == b) cout << "YES\n";
        else cout << "NO\n";

        cout << endl;
    }
    return 0;
}
