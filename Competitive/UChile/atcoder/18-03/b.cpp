#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;


    vec<vec<int>> Areas (n, vec<int> (4, -1));
    int a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> Areas[i][j];
        }
    }


    return 0;
}
