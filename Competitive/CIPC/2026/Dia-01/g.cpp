#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    str ussr;
    cin >> ussr;

    int maxi2 = INT_MIN;
    int maxi3 = INT_MIN;
    char mx2, mx3;

    map<char, int> freq;
    for (char c : ussr)
        freq[ c ]++;

    for (const auto &[ k, val ] : freq) {
        if (val >= maxi2) {
            maxi3 = maxi2;
            maxi2 = val;
            mx3 = mx2;
            mx2 = k;
        } else if (val >= maxi3) {
            maxi3 = val;
            mx3 = k;
        }
    }


    for (int i = 0; i < maxi2; i++)
        cout << mx2;

    cout << endl;


    return 0;
}
