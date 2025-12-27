#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}



int main () {
    fast();

    ll n;
    cin >> n;

    map <int, ll> tams;
    ll maxi = INT_MIN;
    int x;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        tams[x]++;
    }


    auto u = tams.end();--u;
    ll total = 0;
    ll sobrante = 0;
    for (auto val = tams.begin(); val != tams.end();) {
        tams[val->first] = val->second + sobrante;
        ll z = tams[val->first];
        if (val != u) {
            total += (ll) (floor((double) z / 10) * val->first);
            sobrante = val->second % 10;
            tams[val->first] = 0;
        }
        else {
            total += (ll) (floor((double)z / 10 )+1) * val->first;
            //total += (ll) (ceil((double) z / 10) * val->first);
        }
        ++val;
        
    }
    cout << total * 1000 << endl;
    

    return 0;
}