#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    str mes;
    int dia;
    cin >> mes >> dia;
    if ((mes == "OCT" && dia == 31) || (mes == "DEC" && dia == 25)) {
        cout << "yup" << "\n";
    }
    else cout << "nope" << "\n";
    return 0;
}
