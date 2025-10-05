#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int a_idx = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a_idx = i;
        }
    }
    int i = a_idx;
    while (i > 0) {
        if (s[i] == '#') {
            break;       
        }
        if (s[i] == 'T') {
            cout << "ganaste" << endl;
            return 0;
        }
        i--;
    }
    i = a_idx;
    while (i < n) {
        if (s[i] == '#') {
            break;       
        }
        if (s[i] == 'T') {
            cout << "ganaste" << endl;
            return 0;
        }
        i++;
    }
    cout << "perdiste" << endl;
    return 0;
}