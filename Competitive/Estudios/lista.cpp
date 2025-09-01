#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int nodo, arista;
    cin >> nodo >> arista;

    vector<vector<int>> Matriz(nodo, vector<int>());

    for (int i = 0; i < arista; i++) {
        int x,y;
        cin >> x >> y;

        Matriz[x-1].push_back(y-1);
    }

    for (int i = 0; i < nodo; i++) {
        for (int j = 0; j < Matriz[i].size(); j++) {
            cout << Matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}