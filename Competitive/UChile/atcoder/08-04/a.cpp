#include <bits/stdc++.h>
#include <cctype>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;

    str A, B;
    cin >> A >> B;

    bool si = 1;
    for (int i = 0; i < n; i++) {
        char a, b;
        a = A[i];
        b = B[i];

        if (a != b) {
            if ((a == 'l' && b == '1') || (a == '1' && b == 'l')) continue;
            if ((a == '0' && b == 'o') || (a == 'o' && b == '0')) continue;
            else {
                si = 0;
                break;
            }
        }

    }
    if (si) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
