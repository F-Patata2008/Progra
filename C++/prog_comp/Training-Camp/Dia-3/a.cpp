#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    long long odd_count = 0, even_count = 1;
    long long suma_prefix = 0;
    long long ans = 0;
    
    for(int i = 0; i < n; i++) {
        suma_prefix += num[i];

        if(suma_prefix % 2 == 0) {
            ans += odd_count;
            even_count++;
        } else {
            ans += even_count;
            odd_count++;
        }
    }

    cout << ans << endl;

    return 0;
}