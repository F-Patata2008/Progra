#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    
    if (n >= 20 && n <=25) cout << "Todo apagado" << endl;
    else if (n > 25) cout << "Encender aire acondicionado" << endl;
    else if (n < 20) cout << "Encender calefaccion" << endl;

    return 0;
}
