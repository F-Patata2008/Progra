#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int t;
    cin >> t;
    while (t--) {
        str pfhs = "codeforces";
        str ussr;
        cin >> ussr;

        int cont = 0;
        for (int i = 0; i < pfhs.size(); i++) {
            if (pfhs[i] != ussr[i]) {
                cont++;
            }
        }
        cout << cont << endl;
    }
    return 0;
}