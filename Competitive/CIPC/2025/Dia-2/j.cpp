#include <bits/stdc++.h>
#include <iterator>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    str ussr;
    cin >> ussr;
    int sum;
    bool si = 0;

    for (int i = 0; i < size(ussr); i++) {
        sum = 1;
        for (int j = 1; j < 7; j++) {
            if (ussr[i] != ussr[i+j]) break;
            else {
                sum++;
            }
        }
        if (sum == 7) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
