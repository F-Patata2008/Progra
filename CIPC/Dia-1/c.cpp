#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    ll n;
    cin >> n;
    ll suma = 0;
    if (n%2==0) cout << n/2;
    else cout << -1*((n+1)/2);
    return 0;
}
