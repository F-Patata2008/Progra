#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int largo;
    cin >> largo;

    vector<int> a(largo);        
    for  (int i = 0; i < largo; i++) {
        cin >> a[i];
    }



    vector<int> sub(3);
    for  (int i = 0; i < 3; i++) {
        cin >> sub[i];
    }
	
    int contador = 0;
    for (int z = 0; z < (largo-2); z++) {
        if (a[z] == sub[0] && a[z + 1] == sub[1] && a[z+2] == sub[2]) {
            contador++;
        }
    }
    cout << contador << endl;



    return 0;
}
