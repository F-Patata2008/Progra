#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    str ussr;
    cin >> ussr;

    bool si = 0;

    int pos1 = -1, pos2 = -1;
    int posr1 = -1, posr2 = -1;
    int posk = -1;

    for (int i = 0; i < 8; i++) {
        if (ussr[ i ] == 'B') {
            if (pos1 == -1)
                pos1 = i + 1;
            else
                pos2 = i + 1;
        }
        if (ussr[ i ] == 'R') {
            if (posr1 == -1)
                posr1 = i + 1;
            else
                posr2 = i + 1;
        }
        if (ussr[ i ] == 'K')
            posk = i + 1;
    }

    if (posr1 < posk && posk < posr2 && pos1 % 2 != pos2 % 2)
        cout << "Yes";
    else
        cout << "No";


    cout << endl;
    return 0;
}
