#include<bits/stdc++.h>
using namespace std;
#define vec vector
#define str string
#define ll long long


int main() {
    int n;
    cin >> n;
    str ussr;
    cin >> ussr;

    if (ussr[0] == '-' || ussr[n - 1] == '+') {
        cout << "NO" << endl;
        return 0;
    }

    int mas = 0;
    vec<int> pm;
    int menos = 0;
    vec<int> pn;


    for (int z = 0; z < n; z++) {
        if (ussr[z] == '+') {
            mas++;
            pm.push_back(z);
        }
        else {
            menos++;
            pn.push_back(z);
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < mas; i++) {
        cout << pm[i] << " ";
    }
    for (int i = menos - 1; i >= 0; i--) {
        cout << pn[i] << " ";
    }

    cout << endl;
    return 0;
}