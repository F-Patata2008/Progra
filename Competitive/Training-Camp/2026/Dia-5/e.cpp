#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;
typedef string str;
#define vec vector


int main() {
    int t;
    cin >> t;
    while (t--) {
        str ussr;
        cin >> ussr;

        int n = ussr.size() - 2;
        for (int i = 0; i < n + 1; i++) {
            if (i == n) cout << 'i';
            else if (i == n + 1) cout << "  \n";
            else cout << ussr[i];
        }
        cout << endl;
    }

    return 0;
}

