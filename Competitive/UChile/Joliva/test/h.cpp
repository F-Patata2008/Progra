#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, m;
    cin >> n >> m;

    int a = 0, p = 0;

    map<int, bool> probs;

    for (int i = 1; i <= n; i++) {
        probs[ i ] = 0;
    }

    for (int i = 0; i < m; i++) {
        int pact;
        str ussr;
        cin >> pact >> ussr;

        if (ussr != "AC" && probs[ pact ] == 0) {
            p++;
            probs[ pact ] = 0;
        } else if (ussr == "AC" && probs[ pact ] == 0) {
            a++;
            probs[ pact ] = 1;
        }
    }
    cout << a << " " << p << endl;
    return 0;
}
