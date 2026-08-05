#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    char c;
    cin >> c;
    str a = "abcdefghijklmnopqrstuvwxyz";

    cout << a[ c - 'a' + 1 ] << endl;
    return 0;
}
