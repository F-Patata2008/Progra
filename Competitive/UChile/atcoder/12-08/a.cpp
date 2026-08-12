#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int maxi = max(a, b);
    int mini = min(c, d);

    cout << maxi - mini << endl;
    return 0;
}
