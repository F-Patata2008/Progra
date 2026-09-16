#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fast();
    int n;
    cin >> n;

    int largo;
    cin >> largo;

    map<int, int> panes;
    int pri, ult;
    pri = 1e9;
    ult = -1; 
    for (int i = 0; i <n; i++) {
        int pos;
        cin >> pos;
        pri = min(pri, pos);
        ult = max(ult, pos);
        panes[pos]++;
    }

    vec<vec<pair<int, int>>> adj_w (largo);

    for (int i = 0; i < largo; i++) {
        adj_w[i].push_back({i + 1, 1e9});
        adj_w[i + 1].push_back({i, 1e9});
    }
    

    int q;
    cin >> q;
    while (q--) {
        int s, e, t;
        cin >> s >> e >> t;

        int pan = 0;
        
        
    }
    
    
}