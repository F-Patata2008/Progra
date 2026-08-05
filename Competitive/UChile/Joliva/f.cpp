#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    int punt = 0;

    int ussr;
    for (int i = 0; i < n - 1; i++) {
        cin >> ussr;

        punt += ussr;
    }

    int mini = m * n;

    if (mini > punt && mini - punt > k)
        cout << -1;
    else if (punt > mini)
        cout << 0;
    else
        cout << mini - punt;
    cout << endl;


    return 0;
}
