#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int tam1, tam2;
    cin >> tam1 >> tam2;

    int suma1 = 0, suma2 = 0, suma3 = 0, suma4 = 0, suma = 0;
    str ussr;
    cin >> ussr;
    char out [tam2];


    for (int i = 0; i < tam1; i++) {
        if (ussr[i] == '(') suma1++;
        if (ussr[i] == ')') suma2++;
    }

    if (suma1 == (tam2)/2 && suma2 == suma1) cout << ussr << endl;
    else {
        int j = 0;
        for (int i = 0; i <tam1; i++) {

            //cout << suma << "   " << suma3 << "   " << suma4 << endl;
            if (ussr[i] == '(' && suma3 < (tam2 / 2)) {
                suma3++;
                suma++;
                out[j] = '(';
                j++;
            }
            if (ussr[i] == ')' && suma >= 1 && suma4 < (tam2 /2)) {
                out[j] = ')';
                suma--;
                suma4++;
                j++;
            }
            
        }
        for (int i = 0; i < tam2; i++) {
            cout << out[i];
        }
    }



    return 0;
}
