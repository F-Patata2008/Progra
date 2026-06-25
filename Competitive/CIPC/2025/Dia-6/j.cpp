#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        str ussr;
        cin >> ussr;

        int n = ussr.size();

        if (n == 2) cout << "i";
        else {
            for (int i = 0; i < n-2; i++) {
                cout << ussr[i];
            }
            cout << "i";
        }
        cout << endl;
    }
    return 0;
}
