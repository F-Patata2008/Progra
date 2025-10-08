#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000 + 7;

int main() {
    int n;
    cin >> n;

    long long out = 1;
    int z = n;

    while (z > 1) {
        if (z == n) out *= 3;
        else out *= z;
        z--;
        out = out % MOD;
    }
    cout << out << endl;
}
