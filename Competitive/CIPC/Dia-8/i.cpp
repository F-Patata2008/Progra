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
        
        int mini = 1e9;
        for (int i = 0; i < ussr.size(); i++) {
            mini = min(ussr[i] - '0', mini);
        }
        cout << mini << endl;
    }
    return 0;
}
