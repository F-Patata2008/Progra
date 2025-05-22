#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

map<int, int> mem;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        int suma = 0;

        if (mem.find(num) != mem.end()) {
            cout << mem[num] << endl; 
            continue;
        }       
        else {
            for (int i = 0;  i <= 1e6; i++) {
                /*
                if (i >= 1e5) {
                    suma += i / 100000;
                    i = i % 100000;
                }
                if (i >= 1e4) {
                    suma += i / 10000;
                    i = i % 10000;
                }

                if (i >= 1e3) {
                    suma += i / 1000;
                    i = i % 1000;
                }

                if (i >= 100) {
                    suma += i / 100;
                    i = i % 100;
                }

                if (i >= 10 ) {
                    suma += i / 10;
                    i = i % 1000;
                }

                suma += i%10;*/
                suma += (i / 100000);
    
                suma += (i % 100000)/10000;
    
                suma += ((i % 100000)%10000)/1000;
    
                suma += (((i % 100000)%10000)%1000)/100;
    
                suma += ((((i % 100000)%10000)%1000)%100)/10;
    
                suma += ((((i % 100000)%10000)%1000)%100)%10;
                mem[i] = suma;
            }
        }

        cout << mem[num] << endl;
 
    }
    return 0;
}