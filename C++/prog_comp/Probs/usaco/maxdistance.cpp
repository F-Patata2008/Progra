#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int n;
    cin >> n;
    vec<int> x(n);
    vec<int> y(n);
    ll maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    int x2, y2;
    ll d;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            x2=x[i]-x[j];
            y2=y[i]-y[j];

            d = (x2*x2)+(y2*y2);
            maxi = max(d,maxi);
        }
    }
    cout << maxi << "\n";

    return 0;
}
