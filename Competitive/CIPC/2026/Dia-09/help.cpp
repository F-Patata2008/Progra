#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, k;
    cin >> n >> k;

    map<int, map<int, int>, greater<int>> patata;
    map<int, int> c;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        patata[ a ][ b ]++;
        c[ a ]++;
    }

    for (auto l : patata) {
        cout << l.first << ":\n";
        for (auto r : l.second) {
            cout << r.first << ": " << r.second << "\n";
        }
        cout << endl;
    }
    return 0;
}
