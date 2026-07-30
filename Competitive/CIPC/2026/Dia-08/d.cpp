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

    int find_max_pos(int l, int r) {
        return find_max_helper(0, 0, n - 1, l, r);
    }

    int find_max_helper(int nodo, int izq, int der, int l, int r) {
        if (r < izq || l > der)
            return -1;
        if (izq == der)
            return izq;

        int mid = izq + (der - izq) / 2;
        int left_pos = find_max_helper(2 * nodo + 1, izq, mid, l, r);
        int right_pos = find_max_helper(2 * nodo + 2, mid + 1, der, l, r);

        if (left_pos == -1)
            return right_pos;
        if (right_pos == -1)
            return left_pos;

        return (Tree[ 2 * nodo + 1 ] >= Tree[ 2 * nodo + 2 ]) ? left_pos : right_pos;
    }

    void update(int pos, ll val) {
        update_helper(0, 0, n - 1, pos, val);
    }

    void update_helper(int nodo, int izq, int der, int pos, ll val) {
        if (izq == der) {
            Tree[ nodo ] = val;
            return;
        }
        int mid = izq + (der - izq) / 2;
        if (pos <= mid)
            update_helper(2 * nodo + 1, izq, mid, pos, val);
        else
            update_helper(2 * nodo + 2, mid + 1, der, pos, val);
        Tree[ nodo ] = max(Tree[ 2 * nodo + 1 ], Tree[ 2 * nodo + 2 ]);
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vec<ll> a(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[ i ];

        SegmentTree simular(a);

        while (q--) {
            SegmentTree copia = simular;
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            ll sum_r = 0, sum_s = 0;
            ll cont = 0;
            while (true) {
                cont++;
                if (copia.q(l, r) == 0)
                    break;
                if (cont % 2 == 1)
                    sum_r += copia.q(l, r);
                else
                    sum_s += copia.q(l, r);


                ll pos = copia.find_max_pos(l, r);
                copia.update(pos, 0);
            }
            if (sum_s >= sum_r)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    cout << endl;
    return 0;
}
