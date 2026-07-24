#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;

    vec<vec<int>> prod(0);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vec<str> iden(k);
        for (int j = 0; j < k; j++) {
            cin >> iden[ j ];
        }
        sort(iden.begin(), iden.end());
        if (prod.size() == 0) {
            prod.push_back(iden);
        }
    }


    return 0;
}
