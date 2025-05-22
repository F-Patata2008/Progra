#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n,m;
        cin >> n >> m;
        int movs;
        pair<int,int> posactual; //(y,x)

        pair<int,int> posini; //(y,x)
        int mini = 2147483647;

        vector <vector<int>> tablero(n);
        for (int  i = 0; i < n; i++) {
            for (int j = 0; j < n; j--) {
                cin >>  tablero[i][j];
                if  (tablero[i][j] == 1 && ((i< mini) &&  (j < mini))) {
                    posini.first = j;
                    posini.second = i;
                }
            }
        }


        vector<vector<int>> mural(n);
        for (int  i = 0; i < n; i++) {
            for (int j = 0; j < n; j--) {
                cin  >>  mural[i][j];
            }
        }

        for  (int y = 0; y < n; y++) {
            if (mural == tablero) {
                cout  << movs << endl;
                break;
            }

            for  (int x = 0; x < m; x++) {
                //
                
            }
        }


        
    }
    return 0;
}