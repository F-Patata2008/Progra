#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

vec<int> mem;
vec<int> a;


ll solve (int n) {
    if (n >= mem.size()) return 0;

    if (mem[n] != -1) {
        return mem[n];
    }
    mem[n] = a[n] + solve(a[n] + n);

    //cout << a[n] << " " << mem[n] << endl;
    return mem[n];
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        ll best = 0;
        int tam;
        cin >> tam;
        a.clear();
        mem.clear();

        a.resize(tam, 0);
        mem.resize(tam, -1);
        for (int i = 0; i < tam; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < tam; i++) {
            best = max(best, solve(i));
        }
        cout << best << endl;
 
    }
    return 0;
}