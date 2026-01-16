#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, pair<int, int>> piezas;
        for (int i = 0; i < n; i++) {
            int pi, hi;
            cin >> pi >> hi;
            piezas[i] = {pi, hi};
        }
        bool pasa = 1;
        for (int i = 0; i < n - 1; i++) {
            int pi, pj, hi;
            pi = piezas[i].first;
            pj = piezas[i +1].first;
            hi = piezas[i].second;

            if (!(pi + hi > pj)) pasa = 0;
        }

        if (!pasa) cout << "Pep\n";
        else {
            for (int i = 1; i < n - 2; i++) {
                map<int, pair<int,int>> copia = piezas;
                copia.erase(i);
                for (auto it = copia.begin(); it != copia.end();) {
                    int pi, pj, hi;
                    pi = it->second.first;
                    hi = it->second.second;
                    it++;
                    pj = it->second.first;
                    it--;
                }
            }
        }
    }
    cout << endl;
    return 0;
}
