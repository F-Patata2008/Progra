#include <bits/stdc++.h>
#include <time.h>
#include <unistd.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        ll sum = 0;
        if (a == 0 && (b + c + d) > 0)
            cout << 1 << "\n";
        else {
            sum += a;

            sum += 2 * min(b, c);

            int aux = min(b, c);
            c -= aux;
            b -= aux;

            sum += min(a + 1, (b + c + d));


            cout << sum << "\n";
        }
    }
    cout << endl;
    return 0;
}
