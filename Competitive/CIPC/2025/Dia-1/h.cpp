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

        vec <int> a(n);
        ll sum = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            maxi = max(maxi, a[i]);
        }

        if(maxi > sum - maxi) {
            cout << "T" << endl;
        } else {
            if(sum % 2 == 1) {
                cout << "T" << endl;
            } else {
                cout << "HL" << endl;
            }
        } 
    }
    return 0;
}
