#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    str ussr;
    cin >> ussr;

    for (ll i = 0; i < ussr.size() / 2; i++) {
        char copy = ussr[ ussr.size() - 1 - i ];
        ussr[ ussr.size() - 1 - i ] = ussr[ i ];
        ussr[ i ] = copy;
    }
    for (ll i = 0; i < ussr.size(); i++) {
        if (ussr[ i ] == '6')
            ussr[ i ] = '9';
        else if (ussr[ i ] == '9')
            ussr[ i ] = '6';
    }
    cout << ussr << endl;
    return 0;
}
