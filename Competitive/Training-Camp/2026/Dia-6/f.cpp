#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int n;
vec<int> a;

int eli () {
    for (int  i = 0; i < pow(2, n); i++) {

    }


    bool pal = 1;
    for (int i = 0; i < a.size() / 2; i++) {
        if (a[i] != a[n - i - 1]) pal = 0;
    }
    return 0;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.assign(n, -1);
        for (int i = 0; i < n; i++) cin >> a[i];




    }
    return 0;
}
