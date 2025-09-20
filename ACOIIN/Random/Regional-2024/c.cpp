#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    str ric, noc;
    cin >> ric >> noc;
    
    if ((ric == "NNNNNNN" && noc == "DDDDD") || (ric == "DDDDDDD" && noc == "NNNNN"))  {
        cout << "No nos vemos nunca" << endl;
        return 0;
    }
    else {
        for (int i = 0; i < 35; i++) {
            if (ric[i%7] == noc[i%5]) {
                cout << i << endl;
                return 0;
            }
        }
        cout << "No nos vemos nunca" << endl;
        return 0;        
    }

    return 0;
}
