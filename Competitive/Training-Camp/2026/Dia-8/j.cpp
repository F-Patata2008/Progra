#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
typedef float f;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        vec <ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n == 1) {
            if (a[0] == k) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else {

            bool temp = false;
            for (auto num : a) {
                if (num == k) temp = true;
            }

            if (!temp) cout << "no" << endl;
            else {
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

                    if(act) break;
                }

                if (act) cout << "yes" << endl;
                else cout << "no" << endl;
            }
        }

    }
    return 0;
}
