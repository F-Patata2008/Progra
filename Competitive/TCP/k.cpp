#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long out = 1;
    int z = n;

    while (z > 1) {
        if (z == n) out *= 3;
        else out *= z;
        z--;
        out = out % (1000000000 +7);
    }
    cout << out << endl;
}