#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;

    str ussr;
    cin >> ussr;

    int seg = 0;
    int cont = 0;
    
    for (int  i = 0; i < n; i++) {
        if (ussr[i] == 'x') {
            seg++;
            if (seg >= 3) cont++;
        }
        else seg = 0;
    }
    cout << cont << endl;

    return 0;
}
