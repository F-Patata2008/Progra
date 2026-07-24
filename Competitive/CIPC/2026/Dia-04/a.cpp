#include <bits/stdc++.h>
#include <cmath>
#include <functional>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    ll n, k;
    cin >> n >> k;

    vec<ll> q(n), b(n);
    multimap<ll, ll, greater<ll>> scores;

    for (int i = 0; i < n; i++) {
        cin >> q[ i ] >> b[ i ];
        scores.insert({q[ i ] * b[ i ], i});
    }
    b.clear();

    if (scores.begin()->first <= 0) {
        cout << "AUCTION EMPTY" << endl;
        return 0;
    }


    for (auto it = scores.begin(); it != scores.end() && k > 0;) {
        if (it->first > 0) {
            pair<ll, ll> act = *it;
            it++;
            ll q1;
            if (it == scores.end())
                q1 = 0;
            else
                q1 = it->first;
            cout << act.second + 1 << " ";
            cout << floor(q1 / q[ act.second ]) + 1 << "\n";


            k--;
        } else if (k <= 0 || it->first <= 0)
            break;
    }


    return 0;
}
