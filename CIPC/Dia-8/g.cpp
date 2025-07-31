#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n; 
    cin >> n;
    vec <int> a(n); //cantidad de agua en lños tanques;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack <pair <ll, int>> out;
    for (int i = 0; i < n; i++) {
        pair <ll, int> act; //suma y contador;
        act.first = a[i];
        act.second = 1;

        while ((!out.empty()) && ((ll) act.first * out.top().second) <= ((ll) out.top().first * act.second)) {
            act.first += out.top().first;
            act.second += out.top().second;
            out.pop();
        }
        out.push({act});
        // 5 6 2
        // 5 4 4
        // 4.3 4.3 4.3

    }
    vec <double> result;
    while (!out.empty()) {
        ll a = out.top().first;
        int b = out.top().second;
        out.pop();
        double z = (double) a / b;
        for (int  i = 0; i < b; i++) {
            result.push_back(z);
        }
    }
    ranges::reverse(result);
    cout << fixed << setprecision(10);
    for (auto p : result) cout << p << endl;

    return 0;
}
