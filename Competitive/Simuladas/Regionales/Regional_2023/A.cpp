    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define str string

    int main() {
        ll c;
        cin >> c;
        vector<ll> v(c/2);

        for (int x = 0; x < (c/2); x++) {
            cin >> v[x];
        }


        sort(v.begin(), v.end());
        vector <ll> r =  v;
        sort (r.rbegin(), r.rend());

        

        bool g = false;
        ll z = c + 1;
        for (ll x= 0; x <  c/2; x++) {
            ll s = z - v[x];
            for (ll y=0; y <  c/2; y++) {
                if (s == r[y]) {
                    g = true;
                    break;
                }
            }
        }

        if  (!g) {
            cout  << "SI" << endl;
        }
        else cout << "NO" << endl;
        return 0;
    }