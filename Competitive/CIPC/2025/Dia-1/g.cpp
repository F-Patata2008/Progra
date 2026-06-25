#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int cartas[13];
int gan;


int main() {
    int n; //rondas jugadas previamente
    cin >> n;

    for (int i = 0; i < 13; i++) {
        cartas[i] = 4;
    }

    
    //john
    int a,b;
    cin >> a >> b;
    cartas[a-1]--;
    cartas[b-1]--;
    a = min(a,10);
    b = min(b,10);
    int sumJ = a+b;

    //mary
    int c,d;
    cin >> c >> d;
    cartas[c-1]--;
    cartas[d-1]--;
    c = min(c,10);
    d = min(d,10);
    int sumM = c+d;
    
    int ussr;
    int usm = 0;

    for (int i = 0; i < n; i++) {
        cin >> ussr;
        cartas[ussr-1]--;
        ussr = min(ussr,10);
        usm += ussr;
    }

    for(int i = 0; i < 13; i++) {
        if (cartas[i] != 0){
            if (min(i+1,10)+usm+sumM==23) {
                cout << i+1 << "\n";
                return 0;
            }
            else if (min(i+1,10)+usm+sumM<23 && min(i+1,10)+usm+sumJ>23){
                cout << i+1 << "\n";
                return 0;
            }
        }
    }
    cout << -1 << "\n";
    

    return 0;
}
