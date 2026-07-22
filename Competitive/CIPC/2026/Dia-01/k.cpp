#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int sum = c * (a - b);

    if (sum % b != 0) {
        sum /= b;
        sum++;
    } else
        sum /= b;
    cout << sum << endl;
    return 0;
}
