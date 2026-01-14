#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vec<bool> probs (26, 0);
        str ussr;
        cin >> ussr;

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if(!probs[ussr[i] - 'A']) {
                sum++;
                probs[ussr[i] - 'A'] = 1;
            }
            sum++;
        }
        cout << sum << endl;
    }
    return 0;
}
