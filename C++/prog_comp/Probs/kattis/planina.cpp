#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int n;
    cin >> n;
    int out = 2;
    for (int i = 0; i < n; i++) {
        out = out*2;
        out--;
    }
    cout << out*out << "\n";
    return 0;
}
