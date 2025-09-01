#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;
    
    int sum = 0;
    int maxi = -1e9;
    int mini = 1e9;
    double prom = 0;

    int ussr;
    for (int i = 0; i < n; i++) {
        cin >> ussr;
        sum += ussr;
        
        if (ussr > maxi) maxi = ussr;
        if (ussr < mini) mini = ussr;
    }
    prom = sum / n;
    cout << "Total: " << sum << "\n";
    cout << "Maximo: " << maxi << "\n";
    cout << "Minimo: " << mini << "\n";
    cout << "Promedio: " << fixed << setprecision(2) << prom << endl;

    return 0;
}
