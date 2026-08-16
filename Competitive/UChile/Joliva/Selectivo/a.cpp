#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    str ussr;
    cin >> ussr;
    int cont = 0;
    for (int i = 0; i < ussr.size(); i++) {
        if (i + 2 < ussr.size()) {
            if ((ussr[ i ] == 'P' && ussr[ i + 1 ] == 'U' && ussr[ i + 2 ] == 'C'))
                cont++;
        }
    }

    cout << cont << endl;
    ;

    return 0;
}
