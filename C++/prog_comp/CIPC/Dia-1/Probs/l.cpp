#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        str ussr;
        cin >> ussr;

        int suma=0;

        for (char i : ussr) {
            //cout << i << "\n";
            if (i == '0') suma--;
            if (i == '1') suma++;
        }
        if (suma == 0) cout << "E";
        else if (suma < 0) {
            if (suma%4 == 0) cout << "E";
            if (suma%4 == -1) cout << "S";
            if (suma%4 == -2) cout << "W";
            if (suma%4 == -3) cout << "N";
        }
        else {
            if (suma%4 == 0) cout << "E";
            if (suma%4 == 1) cout << "N";
            if (suma%4 == 2) cout << "W";
            if (suma%4 == 3) cout << "S";

        }
        cout << "\n";
    }
    return 0;
}
