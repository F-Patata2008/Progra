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
        int n;
        cin >> n;

        vec<int> a(n, -1);
        for (int i = 0; i < n; i++) cin >> a[i];

        int maxi = INT_MIN;
        int r, l;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += a[j];
                if (sum > maxi * (j - i + 1)) {
                    maxi = sum / (j - i + 1);
                    r = j;
                    l = i;
                }
            }
        }
        cout << maxi << endl;
    }
    return 0;
}
