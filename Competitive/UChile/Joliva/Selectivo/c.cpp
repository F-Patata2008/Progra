#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;

    str letras = {"abcdefghijklmnopqrstuvwxyz"};

    vec<char> a(n);
    for (int i = 0; i < n; i++) {
        cout << letras[ i % 26 ];
    }

    str pc;
    cin >> pc;
    int cont = 0;
    for (char c : pc) {
        if (c == '2')
            cont++;
    }

    while (cont != n) {
    }


    return 0;
}
