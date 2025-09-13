#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;

    vec <str> a(n);
    map <str, int> dist;
   

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dist[a[i]]++;
    }
    
    int m1 = 0;
    str m2 = "";
    for (auto const& pair : dist) {
        if (pair.second > m1) {
            m1 = pair.second;
            m2 = pair.first;
        }

    }

    cout << m2 << endl;

    return 0;
}
