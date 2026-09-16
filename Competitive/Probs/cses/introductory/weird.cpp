#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    ll n;
    cin >> n;
    queue <ll> a;

    a.push(n);

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            a.push(n);
        }
        else {
            n *= 3;
            n++;
            a.push(n);
        }
    }
    while(!a.empty()) {
        cout << a.front() << " ";
        a.pop();
    }
    cout << endl;
    return 0;
}
