#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        str ussr;
        cin >> ussr;

        str timur = "Timur";
        sort(timur.begin(), timur.end());
        sort(ussr.begin(), ussr.end());

        if (ussr == timur) cout << "YES\n";
        else cout << "NO\n";

        cout << endl;

    }
    return 0;
}
