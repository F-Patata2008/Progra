#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    vec <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vec <int> d1 (n, -1), d2(n, -1);

    vec <vec <int>> divisores(n);
    for (int j  = 0; j < n; j++) {
        for (int i = 1; i <= (int)sqrt(a[j]) + 1; i++) {
            if (a[j] % i == 0 && i * i == a[j]) divisores[j].push_back(i);
            else if (a[j] % i == 0 && i * i != a[j] && i > 1 && a[j] / i > 1) {
                divisores[j].push_back(i);
                divisores[j].push_back(a[j] / i);
            }
        }
    }
    bool temp = 0;
    for (int i = 0; i < n; i++) {
        temp = 0;
        for (int j = 0; j < divisores[i].size(); j++) {
            for (int k = j + 1; k < divisores[i].size(); k++) {
               if (gcd(divisores[i][j] + divisores[i][k], a[i]) == 1) {
                    d1[i] = divisores[i][j];
                    d2[i] = divisores[i][k];
                    temp = 1;
                    break;
                } 
            }
            if (temp) break;
        }
    }

    for (int i = 0; i < n; i++) cout << d1[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << d2[i] << " ";
    cout << endl;

    return 0;
}
