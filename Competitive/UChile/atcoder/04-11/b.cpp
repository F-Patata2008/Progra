#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    str ussr;
    cin >> ussr;

    map<char, int> freq;

    bool si = 1;
    bool mayus = 0;
    bool minus = 0;
    str mayu, minu;
    mayu = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    minu = "abcdefghijklmnopqrstuvwxyz";

    for (char c : ussr) {
        freq[ c ]++;
        if (freq[ c ] >= 2) {
            si = 0;
            break;
        }
        if (mayu.find(c) != string::npos)
            mayus = 1;
        if (minu.find(c) != string::npos)
            minus = 1;
    }

    if (si && mayus && minus)
        cout << "Yes";

    else
        cout << "No";

    cout << endl;

    return 0;
}
