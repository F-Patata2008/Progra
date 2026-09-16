// #include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
#define ll long long
#define str string
#define vec vector


int main() {
    freopen("shell.in", "r", stdin);
    int t;
    scanf("%d",&t);
    int p1[3] = {1, 0, 0}; int s1 = 0;
    int p2[3] = {0, 1, 0}; int s2 = 0;
    int p3[3] = {0, 0, 1}; int s3 = 0;

    int a, b, g;
    int copia;

    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &a, &b, &g);
        a--; b--; g--;

        swap(p1[a],p1[b]);
        swap(p2[a],p2[b]);
        swap(p3[a],p3[b]);

        if (p1[g]==1) s1++;
        if (p2[g]==1) s2++;
        if (p3[g]==1) s3++;
    }
    int maxsum = max({s1,s2,s3});
    freopen("shell.out", "w", stdout);
    printf("%d\n", maxsum);
     
    return 0;
}
