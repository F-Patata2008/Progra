#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector
#define endl "\n"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int Canvas;
        cin >> Canvas;
        ll suma = 0;

        priority_queue<ll, vec<ll>, greater<ll>> Oren;

        for (int i = 0; i < Canvas; i++) {
            int x;
            cin >> x;
            Oren.push(x);
        }

        while (Oren.size() != 1) {
            ll x1,x2;
            x1 = Oren.top();
            Oren.pop();
            x2 = Oren.top();
            Oren.pop();
            suma += x1 +x2;

            Oren.push(x1 +x2);

        }
        cout << suma << endl;
        
 
    }
    return 0;
}


