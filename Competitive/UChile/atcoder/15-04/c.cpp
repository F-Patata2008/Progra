#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    str ussr;
    cin >> n >> ussr;

    set <pair<char,int>> busc;


    for (int i = 0; i < n; i++) {
        pair<char,int> act;
        act = {ussr[i], 1};
        busc.insert(act);
        if (i == n - 1) break;
        else {
            for (int j = i + 1; j < n; j++) {
                if (ussr[j] == ussr[i]) {
                    act = {ussr[i], j - i + 1};
                    busc.insert(act);
                }
                else break;
            }
        }
    }


    cout << busc.size() << endl;
    return 0;
}
