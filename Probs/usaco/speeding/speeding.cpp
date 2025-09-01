#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    vec<int> road(100);
    vec<int> trave(100);
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    int maxi = 0;

    cin >> n >> m;
    int cont = 0;
    
    int tam, vel;
    for (int i = 0; i < n; i++) {
        cin >> tam >> vel;
        for (int j = 0; j < tam; j++) {
            road[cont+j]=vel;
        }
        cont+=tam;
    }
    cont = 0;
    for (int i = 0; i < m; i++) {
        cin >> tam >> vel;
        for (int j = 0; j < tam; j++) {
            trave[cont+j]=vel;
        }
        cont+=tam;
    }

    for (int i = 0; i < 100; i++) {
        if (trave[i]>road[i]) {
            maxi = max(maxi, (trave[i]-road[i]));
        }
    }
    //printf("%d\n", maxi);
    cout << maxi << "\n";
    return 0;
}
