#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int x, y;
    cin >> x >> y;
    if (x>0 && y>0) cout << 1 << "\n";
    else if (x<0 && y>0) cout << 2 << "\n";
    else if (x<0 && y<0) cout << 3 << "\n";
    else if (x>0 && y<0) cout << 4 << "\n";
    return 0;
}
