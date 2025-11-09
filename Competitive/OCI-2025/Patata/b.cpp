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

    int n;
    cin >> n;

    multimap <int, pair <int,int>> pelis;
    for (int i = 0; i < n; i++){
        int b, e;
        cin >> b >> e;
        pelis.emplace(b, make_pair(e, i + 1));
    }


    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;

        int mejor = -1e9;
        int cont;
        auto pos = pelis.begin();
        pair<int,int> oj = make_pair(k, -1);
        
        auto z = pelis.upper_bound(k -1);--z;
        /*
        for (auto it = pelis.begin(); it != pelis.upper_bound(k);) {
            if (it->first > k) break;
            
            if (it->second.first > mejor) {
                cont = it->second.second;
                pos = it;
                mejor = it->second.first;
            }

            ++it;
        }
        */
        
        cout << z->second.second << endl;
        //cout << cont << endl;
        pelis.erase(z);

    }
    return 0;
}