#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    str ussr;
    cin >> ussr;
    
    str copy = ussr;
    reverse(ussr.begin(), ussr.end());
    
    if (copy == ussr) cout << "SI" << endl;
    else cout << "NO" << endl;

    return 0;
}
