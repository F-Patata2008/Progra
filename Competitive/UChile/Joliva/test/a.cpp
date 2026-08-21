#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, d;
    cin >> n >> d;
    vec<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[ i ];

    int out = -1;
    for (int i = 1; i < n; i++) {
        if (a[ i ] - a[ i - 1 ] <= d) {
            out = a[ i ];
            cout << out << endl;
            return 0;
        }
    }
    cout << out << endl;


    return 0;
}
