#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int s,n;
    cin >> s >> n;
    int ussr,usr;
    pair<int,int> a;

    vec<pair<int,int>> drag(n);
    for (int i = 0; i < n; i++) {
        cin >> ussr >> usr;
        a = make_pair(ussr, usr);
        drag[i] = a;
    }
    
    sort(drag.begin(), drag.end());

    for (int i  = 0; i < n; i++) {
        if (s > drag[i].first) {
            s += drag[i].second;
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
