#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    if ((a > 0 && b > 0 && c > 0) && (a + b + c > n - 1) && (n > 2)) cout << "YES" << "\n";
    else cout << "NO" << "\n";

    return 0;
}
