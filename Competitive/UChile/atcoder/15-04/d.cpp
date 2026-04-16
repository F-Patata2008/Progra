#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, m;
    cin >> n >> m;

    vec <int> votos (m);
    for (int i = 0; i < m; i++) cin >> votos[i];


    map <int,int> bots;
    pair <int,int> win = {0,0};

    for (int i = 0; i < m; i++) {
        bots[votos[i]]++;
        pair<int,int> act = {votos[i],bots[votos[i]]};

        if (act.second >= win.second && act.first < win.first) {
            win = act;
        }
        else if (act.second > win.second) {
            win = act;
        }

        cout << win.first << endl;
    }
    cout << endl;

    return 0;
}
