#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    double miles;
    cin >> miles;

    double out = miles*1000;
    out = out*5280;
    out = out/4854;

   // cout << out << "\n";
    cout << lround(out) << "\n";
    



    return 0;
}

