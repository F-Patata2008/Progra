#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
#define str string
#define vec vector
//usaco de mrd usa freeopen, scanf y printf


int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    vec<int> capacity(3);
    vec<int> milk(3);
    
    scanf("%d %d", &capacity[0], &milk[0]);
    scanf("%d %d", &capacity[1], &milk[1]);
    scanf("%d %d", &capacity[2], &milk[2]);

    //for (int i = 0; i < 3; i++) cin >> capacity[i] >> milk[i];


    for (int i = 0; i < 100; i++) {
        int j = i % 3;
        int k = (i+1)%3;
        //cout << i << " " << j << " " << k << "\n";
        //cout << milk[j] << " " << milk[k] << "\n";


        if (milk[j]+milk[k]<=capacity[k]) {
            milk[k] += milk[j];
            milk[j] = 0;
        }
        else if (milk[j]+milk[k]>capacity[k]) { 
            milk[j] = milk[j]+milk[k]-capacity[k];
            milk[k] = capacity[k];
        }
    }
    //cout << "\n" << "\n";
    for (int i = 0; i < 3; i++) {
        printf("%d\n", milk[i]);
        //cout << milk[i] << "\n";
    }


    return 0;
}
