#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

bool limites (int x, int y) {
    return ();
}

void DFS (int x, int y) {
    if (limites(x, y)) return;
    if (visited[x][y]) return;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            
        }
    }
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<bool>> visited;
vector<vector<int>> Matriz;

int main() {
    int  n, m;
    cin >> n >> m;

    Matriz.assign(n, vector<int>(m,0));
    visited.assign(n, vector<bool>(m, false));


    for (int i = 0; i < n; i++) {
        str linea;
        cin >> linea;
        for (int j = 0; j < m; j++) {
            if (linea[j] == '.') Matriz[i][j] = 1;
            else visited[i][j] = true;
        }
    }
    int subgrafos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                DFS(i, j);
            }
        }
    }




    return 0;
}