#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        str ussr;
        cin >> ussr;

        int suma = 0;

        for (char i : ussr) {
            if (i == '0') suma--;
            if (i == '1') suma++;
        }
        if (suma % 4 == 0) cout << "E";
        else if (suma % 4 == 3 || suma % 4 == -1) cout << "S";
        else if (suma % 4 == 2 || suma % 4 == -2) cout << "W";
        else if (suma % 4 == 1 || suma % 4 == -3) cout << "N";

        cout << endl;
    }
    return 0;
}
