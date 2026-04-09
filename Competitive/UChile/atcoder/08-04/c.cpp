#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int N, M;
    int H, maxH;
    cin >> N >> M >> H >> maxH;
    str moves;
    cin >> moves;

    multiset <pair <int,int>> sal;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        sal.insert({x,y});
    }
    pair pos = {0,0}; //x, y;
    bool si = 1;
    for (int i = 0; i < moves.size(); i++) {
        char  mov = moves[i];
        if (mov == 'R') pos.first++;
        else if (mov == 'L') pos.first--;
        else if (mov == 'U') pos.second++;
        else if (mov == 'D') pos.second--;

        H--;
        if (H <= -1) {
            si = 0;
            break;
        }
        if (H < maxH && sal.find(pos) != sal.end()) {
            H = maxH;
            sal.erase(sal.find(pos));
        }

    }

    if (si) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
