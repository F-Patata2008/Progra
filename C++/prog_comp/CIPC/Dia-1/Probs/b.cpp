#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        int ussr; cin >> ussr;
        if (ussr == 0) cout << "UP" << "\n";
        else if (ussr == 15) cout << "DOWN" << "\n";
        else cout << -1 << "\n";
        return 0;

    }
    vec<int> algo(n);

    for (int i = 0; i < n; i++) {
        cin >> algo[i];
    }
    n--;
    if (algo[n] == 15) cout << "DOWN" << "\n";
    else if (algo[n] == 0) cout << "UP" << "\n";

    else {
        if (algo[n-1] < algo[n]) cout << "UP" <<"\n";
        else if (algo[n-1] > algo[n]) cout << "DOWN" << "\n";
    }



    return 0;
}
