#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, s1, out;
        int hh, min;
        cin >> hh >> min;
        s = 24-hh;
        s1 = 60-min;
        cout << (s * 60) + s1 - 60 << endl;
    }
    return 0;
}
