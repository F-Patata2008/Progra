#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    
    n = n % 9;
    if (n == 0) cout << "Rojo" << endl;
    else if (n <= 3) cout << "Verde" << endl;
    else if (n <= 7) cout << "Amarillo" << endl;
    else if (n <= 9) cout << "Rojo" << endl;

    return 0;
}
