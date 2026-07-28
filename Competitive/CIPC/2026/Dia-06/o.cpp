#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    vec<int> stones(n);
    for (int i = 0; i < n; i++)
        cin >> stones[ i ];

    bool si = 1;

    // Sam va primero
    // luego Jon
    // si sacas i piedras del stack s[j], no se puede volver a sacar i piedras de ese stack s[j]


    if (n == 1)
        si = 0;
    else {
        vec<set<int>> movs(n);
        vec<int> dp;
    }


    if (si)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


    return 0;
}
