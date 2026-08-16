#include <bits/stdc++.h>
#include <climits>
#include <numeric>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector


struct SegmentTree {
    int n;
    vec<int> Tree;

    SegmentTree(vec<int> &a) {
        n = a.size();
        Tree.resize(4 * n);
        build(a, 0, 0, n - 1);
    }

    void build(vec<int> &a, int nodo, int izq, int der) {
        if (izq == der) {
            Tree[ nodo ] = a[ izq ];
            return;
        }
        int mid = izq + (der - izq) / 2;
        build(a, 2 * nodo + 1, izq, mid);
        build(a, 2 * nodo + 2, mid + 1, der);
        Tree[ nodo ] = gcd(Tree[ 2 * nodo + 1 ], Tree[ 2 * nodo + 2 ]);
    }

    int q(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    int query(int nodo, int izq, int der, int l, int r) {
        if (r < izq || l > der)
            return 0;
        if (l <= izq && der <= r)
            return Tree[ nodo ];
        ll mid = izq + (der - izq) / 2;
        return gcd(query(2 * nodo + 1, izq, mid, l, r), query(2 * nodo + 2, mid + 1, der, l, r));
    }
};


int main() {
    int n;
    cin >> n;

    vec<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[ i ];

    int maxi = INT_MIN;

    vec<int> copy(n);


    for (int i = 0; i < n; i++) {
        copy = c;
        copy[ i ]++;
        SegmentTree GCD(copy);

        maxi = max(maxi, GCD.q(0, n - 1));
    }

    cout << maxi << endl;
    ;

    return 0;
}
