#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int a, b, c;
    int d, e, f;
    int X;

    cin >> a >> b >> c;
    cin >> d >> e >> f;
    cin >> X;


    // taka es abc
    ll taka = X / (a + c);
    taka *= a;
    taka += min((X % (a + c)), a);
    taka = taka * b;


    // aoki es def
    ll aoki = X / (d + f);
    aoki *= d;

    aoki += min((X % (d + f)), d);
    aoki = aoki * e;


    if (aoki > taka)
        cout << "Aoki";
    else if (aoki < taka)
        cout << "Takahashi";
    else
        cout << "Draw";

    cout << endl;


    return 0;
}
