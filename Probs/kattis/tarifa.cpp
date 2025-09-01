#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int plan, meses;
    cin >> plan >> meses;

    int uso = 0;
    int mes;
    for (int i = 0; i < meses; i++) {
        cin >> mes;
        uso+=plan-mes;

    }
    cout << uso+plan << "\n";
    
    return 0;
}
