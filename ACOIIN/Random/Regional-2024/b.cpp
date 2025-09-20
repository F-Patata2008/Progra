#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    ll n, m;
    cin >> n >> m;
    
    ll sol;
    sol = (n*m)/2;

    if (n * m % 2 == 0) cout << sol << " " << sol << endl;
    else cout << sol + 1 << " " << sol << endl;

    return 0;
}
