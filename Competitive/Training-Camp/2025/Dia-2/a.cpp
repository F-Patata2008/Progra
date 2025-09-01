#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

int main() {
        str ussr;
        cin >> ussr;
        priority_queue<ll, vec<ll>, greater<ll>> Oren;


        for (int x = 0; x < ussr.size(); x++) {
            if (ussr[x] != '+') {
                Oren.push(ussr[x]-'0');
            }
        }
        cout << endl << endl;

        while (Oren.size() > 1) {
            cout << Oren.top() << "+";
            Oren.pop();
        }
        cout << Oren.top() << endl;
    return 0;
}