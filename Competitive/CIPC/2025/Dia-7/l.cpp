#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    vec <int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a .end());

    int maxi = a[n-1];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += maxi -a[i];
    }
    cout << sum << endl;


    return 0;
}
