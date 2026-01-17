#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    int n;
    cin >> n;

    vec<int> cangrejos (n);
    vec<int> muertes (n , -1);
    for (int i = 0; i < n; i++) cin >> cangrejos[i];

    int ronda = 0;
    int ceros = 0;
    while (ceros  < n - 1) {
        //cout << ceros << endl;
        ronda++;
        set<pair<int, int>> der;
        for (int i = 0; i < cangrejos.size(); i++) {
            if (cangrejos[i] == -1) continue;

            int c_act = cangrejos[i];
            int j = i + 1;
            while (j < cangrejos.size()) {
                if (cangrejos[j] >= c_act) {
                    der.insert({j, cangrejos[j]});
                    break;
                }
                j++;
            }
            j = i - 1;
            while (j >= 0) {
                if (cangrejos[j] >= c_act) {
                    der.insert({j, cangrejos[j]});
                    break;
                }
                j--;
            }          
            

        }
        for (auto patata : der) {
            if (patata.second - 1 > 0) cangrejos[patata.first] = patata.second - 1;
            else {
                muertes[patata.first] = ronda;
                ceros++;
                cangrejos[patata.first] = -1;
            }
        }

    }
    for (int i = 0; i < n; i++) cout << muertes[i] << " ";
    cout << endl;
}