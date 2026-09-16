struct Segment_Tree {
    int n;
    vec <int> Tree;

    Segment_Tree (vec <int>& a) {
        n = a.size();
        Tree.resize(4 * n);
        build();

    }

    void build (vec <int>& a, int nodo, int izq, int der) {
        if (izq = der) {
            Tree[nodo] = a[izq];
            return;
        }

        int mid = izq + (der - izq);
        build(a, 2 * nodo, izq, mid);
        build(a, 2 * nodo + 1, mid + 1, der);
        Tree[nodo] = min(Tree[2 * nodo], Tree[2 * nodo + 1]);
    }
}


