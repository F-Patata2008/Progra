#include <bits/stdc++.h>
#include <iterator>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int n; cin >> n;

    vec<int> profes(n);
    vec<int> weones(n);
    vec<int> mierda(n);

    ll suma = 0;
    int p;
    int w;

    for (int i = 0; i < n; i++) cin >> profes[i];
    for (int i = 0; i < n; i++) cin >> weones[i];
    for (int i = 0; i < n; i++) mierda[i] =profes[i]-weones[i];

    sort(mierda.begin(), mierda.end());

    for(int i = 0; i < n; i++) {
        auto it = std::upper_bound(mierda.begin()+i+1, mierda.end(), -mierda[i]);
        suma+=distance(it,mierda.end());
    }
    cout << suma << endl;

    return 0;
}
