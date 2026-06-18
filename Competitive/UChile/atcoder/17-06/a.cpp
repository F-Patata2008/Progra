#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int a, b;
    cin >> a >> b;

    if (a == 0 && b > 0) cout << "Silver";
    else if (a > 0 && b == 0) cout << "Gold";
    else cout << "Alloy";
    cout << endl;
    return 0;
}
