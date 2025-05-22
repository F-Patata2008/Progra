#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int nodo, arista;
    cin >> nodo >> arista;

    vector<vector<int>> Matriz(nodo,vector<int>(nodo,0));
    for (int i = 0; i < arista; i++) {
        int x, y;
        cin >> x>>y;
        Matriz[x-1][y-1] = 1;
    }

    for (int i = 0; i < nodo; i++) {
        for (int j = 0; j < nodo; j++) {
            cout << Matriz[i][j] << " ";
        }

    }

    return 0;
}
