#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n; cin >> n;
    str ussr;
    cin >> ussr;
    
    vec <int> a;

    for (int i = 0; i < n; i++) {
        if (ussr[i] == '0' || ussr[i] == '1') continue;
        else if (ussr[i] == '4') {
            a.push_back(3);
            a.push_back(2);
            a.push_back(2);
        }
        else if (ussr[i] == '6') {
            a.push_back(5);
            a.push_back(3);
        }
        else if (ussr[i] == '8') {
            a.push_back(7);
            a.push_back(2);
            a.push_back(2);
            a.push_back(2);

        }
        else if (ussr[i] == '9') {
            a.push_back(7);
            a.push_back(3);
            a.push_back(3);
            a.push_back(2);
        }
        else a.push_back(ussr[i] - '0');
    }
    sort(a.rbegin(), a.rend());
    for (int out : a) {
        cout << out;
    }
    cout << endl;
    return 0;
}
