#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    str a,b;
    cin >> a >> b;
    

    queue <char> c, d;
    for (int i = 0; i < a.size(); i++) {
        c.push(a[i]);
        d.push(b[i]);
    }


    char temp;
    for (int i = 0; i < a.size(); i++) {
        if (c == d) {
            cout << "SI" << endl;
            return 0;
        }
        temp = c.front();
        c.pop();
        c.push(temp);
    }

    cout << "NO" << endl;

    return 0;
}
