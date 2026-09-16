#include<bits/stdc++.h>
using namespace std;
#define vec vector
#define str string
#define ll long long


int main() {
    int n, m;
    cin >> n >> m;

    if (n == 2) {
        int c = m;
        int g1 = 0;
        int g2 = 0;

        vec <int> victorias (m, -1);
        while (c--) {
            int x, y;
            cin >> x >> y;
            if (x == 0) victorias[m - 1 - c] = 0;
            else victorias[m - 1 - c] = 1;
        }

        vec <int> bolitas (m, -1);
        int b1 = 0;
        int b2 = 0;
        while (m--) {
            if (victorias[m] == 0) g1++;
            else g2++;

            if (g1 >= g2){
                bolitas[m] = 0;
                b1++;
            }
            else {
                bolitas[m] = 1;
                b2++;
            }
        }
        
        cout << b1 << " " << b2 << endl;        
        return 0;
    }


    else {
        vec<vec<int>> noches (n, vec<int>(m , 0));
        vec<vec<int>> c (n, vec<int> (0));
        queue <int> cop;

        int x,y;
        for (int i = 0; i < m; i++) {
            //ganador se lleva canica i + canicas de otro weon
            cin >> x >> y;
            vec<int> gana (1 + c[y].size());
            gana[0] = i;
            for (int i = 0; i < c[y].size(); i++) {
                gana[i + 1] = c[y][i];
            }
            sort(gana.begin(), gana.end());

            merge (c[x].begin(), c[x].end(), gana.begin(), gana.end(), front_inserter(c[x]));

            sort(c[x].begin(), c[x].end());

            for (int j = 0; j < n; j++) {
                for (int k : c[j]) {
                    noches[j][k]++;
                }
            }
            
            
        }
        c.clear();

cout << 1 << endl;
        vec<int> ninos (n, 0);
        for (int i = 0; i < m; i++) {
            int maxi = INT_MIN;
            int pos;

            for (int j = 0; j < n; j++) {
                if (noches[j][i] > maxi) {
                    maxi = noches[j][i];
                    pos = i;
                }
            }
            ninos[pos]++;
            noches[i].clear();
        }
        noches.clear();


        for (int i : ninos) cout << i << " ";
        ninos.clear();
        cout << endl;
    }
}