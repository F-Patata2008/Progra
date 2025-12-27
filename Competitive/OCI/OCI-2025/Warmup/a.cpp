#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned ll

int main(){
    ull n, x;
    cin >> n >> x;

    vector <ull> patata(n);
    vector <unsigned long long> prefix(n);


    for (ull i = 0; i < n; i++) {
        cin >> patata[i];
    }

    sort(patata.begin(), patata.end());


    prefix[0] = patata[0];
    for (ull i = 1; i < n; i++) {
        prefix[i] = (ll) prefix[i - 1] + patata[i];
    }

    auto z = lower_bound(prefix.begin(), prefix.end(), x/2);
    auto y =lower_bound(prefix.begin(), prefix.end(), x);


    //cout << prefix.end() - prefix.begin() << endl;
    for (ull i = 0 ; i < y - prefix.begin(); i++) {
        for (ull j = 0; j < i; j++) {
            if ((ull) 2 * (prefix[i] - prefix[j]) >= (ull) x && (ull) prefix[i] - prefix[j] <= (ull) x) {
                cout << 1 << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}