#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;

    vec <int> nums (n);
    int maxi1 = 0;
    int maxi2 = -1;

    while (n--) {
        int act;
        cin >> act;
        if (act > maxi1) {
            maxi2 = maxi1;
            maxi1 = act;
        }
        else if (act > maxi2 && act < maxi1) maxi2 = act;
    }

    cout << maxi2 << endl;

    return 0;
}
