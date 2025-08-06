#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    
    int sum = 0;

    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    cout << n - sum << endl;

    return 0;
}
