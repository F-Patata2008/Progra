#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    
    int m,n,k;
    scanf("%d %d %d", &m, &n, &k);

    vector<str> matriz(m);
    vector<str> out(m*k);

    for (int i = 0; i < m; i++) {
        cin >> matriz[i];
    }

    for(int i = 0; i < m; i++) {
        for (int l = 0; l < k; l++) {
            for (int j = 0; j < n; j++) {
                for (int a = 0; a < k; a++) {
                    printf("%c", matriz[i][j]);
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}
