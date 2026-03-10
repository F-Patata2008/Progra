#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    double n = 1;

    for (int i = 1; i <= 100; i++) {
        n = n * (366 - i) / 365;
        cout << "I: " << i << endl << "P: " << n << endl;
    }
    cout << endl;
    return 0;
}
