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
    fast();
    int n;
    cin >> n;
    
    vec<int> cangrejos (n);
    vec<pair<int,int>> c2 (n);

    vec<int> muertes (n , -1);
    for (int i = 0; i < n; i++) {
        int ussr;
        cin >> ussr;
        c2[i] = {i, ussr};
    }

    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }

    int ronda = 0;
    while (c2.size() > 1) {
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> der;
        vec<bool> cop (c2.size(), 0);
        //queue<pair<int, int>> der;
        ronda++;
        for (int i = 0; i < c2.size(); i++) {
            int c_act = c2[i].second;
            int j = i + 1;
            while (j < c2.size()) {
                if (c2[j].second >= c_act && !cop[j]) {
                    der.push(c2[j]);
                    cop[j] = 1;
                    break;
                }
                j++;
            }
            j = i - 1;
            while (j >= 0) {
                if (c2[j].second >= c_act && !cop[j]) {
                    der.push(c2[j]);
                    cop[j] = 1;
                    break;
                }
                j--;
            }          
            

        }
        int i = 0;
        vec <int> el;
        while (!der.empty()) {
            pair<int, int> act = der.top();
            if (act == c2[i]) {
                der.pop();
                if (act.second - 1 > 0) c2[i] = {act.first, act.second - 1};
                else {
                    muertes[act.first] = ronda;
                    el.push_back(i);
                    continue;
                }
            }
            i++;
        }
        sort(el.rbegin(), el.rend());
        for (int j = 0; j < el.size(); j++) c2.erase(c2.begin() + el[j]);
            

    }
    for (int i = 0; i < n; i++) cout << muertes[i] << " ";
    cout << endl;
}