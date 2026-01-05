#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;
typedef string str;

#define vec vector

int n, m;
vec<int> vis;
vec<vec<int>> brains;



void dfs(int patata) {
    vis[patata] = 1;
    for (int  i = 0; i < (int) brains[patata].size(); i++) {
        int v = brains[patata][i];
        if (vis[v] == -1) {
            dfs(v);
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    brains.assign(n, vec<int> ());

    for (int i = 0; i < m; i++) {
        int cerA, cerB;
        cin >> cerA >> cerB;
        cerA--; cerB--;
        brains[cerA].push_back(cerB);
        brains[cerB].push_back(cerA);

    }
    vis.assign(n, -1);
    int xtra = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i] == -1) {
            xtra++;
            dfs(i);
        }
    }

    if (xtra == 1 && n - 1 == m) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}

