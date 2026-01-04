#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vec<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vec<bool> vist(n - 1);
        for (int i = 0; i < n - 1; i++){
            if ((ll) a[i] < (ll) 2 * a[i + 1]) {
                vist[i] = 1;
            }
            else vist[i] = 0;
        }

        int cont = 0;

        int conce = 0;

        for (int i = 0; i < n - 1; i++) {
            if (vist[i]) conce++;
            else conce = 0;

            if (conce >= k) cont++;
        }


        cout << "\n" << cont << "\n" << "\n";
    }
    cout << endl;
    return 0;
}
