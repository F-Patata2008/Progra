#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

struct comp {
    bool operator()(const pair<int, int> &value1, const pair<int, int> &value2) const {
        return ((ll) value1.first * value2.second > (ll) value1.second * value2.first);
    }
};


int main() {
    int n;
    cin >> n;


    multimap<pair<ll, ll>, ll, comp> p;
    multimap<int, int> op;

    for (int i = 0; i < n; i++) {
        int c, m;
        cin >> c >> m;
        c++;
        m += 2;

        p.insert({{c, m}, i});
    }


    for (auto a : p) {
        cout << a.second + 1 << " ";
    }
    cout << endl;

    return 0;
}
