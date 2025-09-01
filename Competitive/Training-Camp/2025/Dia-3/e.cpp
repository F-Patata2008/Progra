#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

int main() {
    int original;
    cin >> original;
    int copy = original;
    int cont = 1;

    while (copy != 1) {
        copy = copy/2;
        cont++;
    }

    cout << cont * original << endl;




    return 0;
}