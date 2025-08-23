#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    ll n;
    cin >> n;
    
    if (n % 4 == 0 && n % 100 != 0) cout << "Es bisiesto" << endl;
    else if (n % 400 == 0) cout << "Es bisiesto" << endl;
    else cout << "No es bisiesto" << endl; 

    return 0;
}
