#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define f float
#define endl '\n'

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        ll n, k;
        cin >> n >> k;

        vec <ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n == 1) {
            if (a[0] == k) {
                cout << "yes" << endl;
                continue;
            }
            else {
                cout << "no" << endl;
                continue;
            }
        }

        bool temp = false;
        for (auto num : a) {
            if (num == k) {
                temp = true;
                break;
            }
        }

        if (!temp) {
            cout << "no" << endl;
            continue;
        }

        bool act = false;
        for (int i = 0; i < n; i++) {
            if (a[i] >= k) { 
                for (int j = i + 1; j <= i + 2 && j < n; j++) {
                    if (a[j] >= k) {
                        act = true;
                        break;
                    }
                }
            }

            if(act) {
                break;
            }
        }

        if (act) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
