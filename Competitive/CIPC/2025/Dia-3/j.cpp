#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;

    map <int, int> x;
    map <int, int> y;

    map <pair <int, int>, int > pc;

    for (int i = 0; i < n; i++) {
        int xs, ys;
        cin >> xs >> ys;
        x[xs]++; y[ys]++;
        pc[{xs, ys}]++;
    }
    ll sum  = 0;
    
    for  (auto const& [xs, cant] : x) sum += (ll)cant * (cant - 1) / 2;

    for  (auto const& [ys, cant] : y) sum += (ll)cant * (cant - 1) / 2;


    for  (auto const& [s, cant] : pc) sum -= (ll)cant * (cant - 1) / 2;




    cout << sum << endl;

    return 0;
}
