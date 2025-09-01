#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

int main() {
    ll tam;
    cin >> tam;
    vec<ll> arr(tam);

    ll cont = 0; //de puros -1
    ll co = 0;   //de puros 0
    ll c = 0;    //de puros 1
    ll min = 0;



    for (int i = 0; i < tam; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            min += (1 + arr[i]) * -1;
            cont++;
        }
        else if (arr[i] == 0) co++;
        else if (arr[i] > 0) {
            min += arr[i] - 1;
            c++;
        }
    }

    if (co == tam) cout << tam << endl;
    else if (cont % 2 != 0 && co > 0) cout << min + co  << endl;
    else if (cont % 2 != 0 && co == 0) cout << min + 2 << endl;
    else if (cont % 2 == 0 && co == 0) cout << min << endl;
    else if (cont % 2 == 0 && co > 0) cout << min + co << endl;



    return 0;
}