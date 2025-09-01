#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int t;
    cin >> t;
    int r, e, c;
    while (t--) {
        cin >> r >> e >> c;
        if (r<(e-c)) cout << "advertise" << "\n";
        if (r==(e-c)) cout << "does not matter" << "\n";
        if (r>(e-c)) cout << "do not advertise" << "\n";
    }
    return 0;
}
