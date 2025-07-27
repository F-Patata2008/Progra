#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    vec <int> A(n);
    vec <int> S(n);
    vec <bool> Yes(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    int izq, der, mid;
    izq = 0;
    der = INTMAX_MAX;

    while (izq <= der) {
        mid = izq + (der - izq) / 2;

    }

    return 0;
}
