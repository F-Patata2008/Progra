#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        queue<pair<int, int>> cajones;
        bool si = 0;
        cajones.push({n, 0});
        int sum;

        set<int> sipi;

        while (!cajones.empty()) {
            int dividir = cajones.front().first;
            sum = cajones.front().second;
            if (dividir == k) {
                si = 1;
                break;
            }
            else if (dividir < k) {
                cajones.pop();
                continue;
            }

            else {
                cajones.pop();
                sum++;
                if (sipi.find(dividir) != sipi.end()) {
                    continue;
                }
                sipi.insert(dividir);
                int d1, d2;
                d1 = dividir/2;
                d2 = dividir - d1;

                cajones.push({d1, sum});
                cajones.push({d2, sum});
            }
        }

        if (si) cout << sum << endl;
        else cout << -1 << endl;
    }
    cout << endl;
    return 0;
}
