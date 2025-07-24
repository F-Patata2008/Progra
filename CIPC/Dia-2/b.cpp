#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << endl;
        str ussr; cin >> ussr;
        int sum = 0;

        if(ussr.size()%2!=1) {
            //Compureba si es cuadrada
            for (int i = 0; i < ussr.size()/2; i++) {
                if (ussr[i] == ussr[i+(ussr.size()/2)]) {
                    sum++;
                }
            }
            if (sum == ussr.size()/2) cout << "YES\n";
            else cout << "no\n";
        }
        else cout << "no\n";
    }
    return 0;
}
