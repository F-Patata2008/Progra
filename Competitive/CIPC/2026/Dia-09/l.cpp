#include <bits/stdc++.h>
#include <functional>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, k;
    cin >> n >> k;

    int a, b;
    map<int, map<int, int>, greater<int>> p;
    map<int, int, greater<int>> c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        p[ a ][ b ]++;
        c[ a ]++;
    }


    int cont = 0;
    bool si = 0;
    for (auto l : p) {
        int pos = l.first;
        for (auto r : l.second) {
            if (k > r.second)
                k -= r.second;
            else if (k <= r.second) {
                cont = r.second;
                si = 1;
                break;
            }
        }
        if (si)
            break;
    }
    cout << cont << endl;
    return 0;
}
