#include<bits/stdc++.h>
using namespace std;
#define vec vector
#define str string
#define ll long long



int main(){
    int n, q;
    cin >> n >> q;

    vec <int> sopaipas (n, -1);
    int c = n;
    while (c--) cin >> sopaipas[n - 1 - c];

    vec <pair <int, int>> cam (q);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cam[i] = {a,b};
    }

    if (q == 0) {
        for (int i = 0; i < q + 1; i++) {
            
        }
    }
   


}