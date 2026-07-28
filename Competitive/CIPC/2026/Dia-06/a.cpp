#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector


struct SegmentTree {
    int n;
    vec<ll> Tree;

    SegmentTree(vec<ll> &a) {
        n = a.size();
        Tree.resize(4 * n);
        build(a, 0, 0, n - 1);
    }

    void build(vec<ll> &a, int nodo, int izq, int der) {
        if (izq == der) {
            Tree[ nodo ] = a[ izq ];
            return;
        }
        int mid = izq + (der - izq) / 2;
        build(a, 2 * nodo + 1, izq, mid);
        build(a, 2 * nodo + 2, mid + 1, der);
        Tree[ nodo ] = max(Tree[ 2 * nodo + 1 ], Tree[ 2 * nodo + 2 ]);
    }
    ll q(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    ll query(int nodo, int izq, int der, int l, int r) {
        if (r < izq || l > der)
            return LLONG_MIN;
        if (l <= izq && der <= r)
            return Tree[ nodo ];
        int mid = izq + (der - izq) / 2;
        return max(query(2 * nodo + 1, izq, mid, l, r), query(2 * nodo + 2, mid + 1, der, l, r));
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vec<ll> pos(1e9, 0);
        for (int i = 0; i < n; i++) {
            int ussr;
            cin >> ussr;
            pos[ ussr ] = 1;
        }
        SegmentTree busc(pos);

        while (q--) {
            int k;
            cin >> k;
        }
    }
    return 0;
}
