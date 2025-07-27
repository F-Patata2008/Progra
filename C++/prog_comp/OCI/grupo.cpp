#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, k;
    cin >> n >> k;
    int sum = 0;

    vec <int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    cout << sum/k << endl;
    return 0;
}
