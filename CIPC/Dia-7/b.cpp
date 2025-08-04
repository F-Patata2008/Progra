#include <bits/stdc++.h>
using namespace std;

const int MAXA = 10000001;
int primo_chico[MAXA];


typedef long long ll;
typedef string str;
#define vec vector

void sieve () {
    iota(primo_chico, primo_chico + MAXA, 0);
    for (int i = 2; i*i < MAXA; i++) {
        if (primo_chico[i] == i) {
            for (int j = i * i; j < MAXA; j += i) {
                if (primo_chico[j] == j) primo_chico[j] = i;
            }
        }
    }
}



int main() {
    sieve();

    int n;
    cin >> n;
    vec <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vec <int> d1 (n, -1), d2(n, -1);

    for (int i = 0; i < n; i++) {
        int act = a[i];
        int numi = primo_chico[act];

        if (numi == act) continue;

        int ff = 1;
        while (act % numi == 0) {
            ff *= numi;
            act /= numi;
        }
        if (act > 1) {
            d1[i] = ff;
            d2[i] = act;
        }
    }



    for (int i = 0; i < n; i++) cout << d1[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << d2[i] << " ";
    cout << endl;

    return 0;
}
