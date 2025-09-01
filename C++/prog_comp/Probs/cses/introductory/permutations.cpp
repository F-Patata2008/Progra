#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    queue <int> par;
    queue <int> inpar;
    
    if (n == 1) cout << 1 << endl;
    else if (n > 3) {
        for (int i = 1; i <= n; i++) {
            if ( i % 2 == 0) par.push(i);
            else inpar.push(i);
        }
        while (!par.empty()) {
            cout << par.front() << " ";
            par.pop();
        }
        while (!inpar.empty()) {
            cout << inpar.front() << " ";
            inpar.pop();
        }
        cout << endl;
    }
    else cout << "NO SOLUTION" << endl;

    return 0;
}
