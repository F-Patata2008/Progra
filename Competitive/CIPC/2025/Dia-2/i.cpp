#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vec<int> a(n), b(n), c(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int sumA, sumB;
        sumA = 0; sumB = 0;

        // 3 les gusta a y b
        // 2 les gusta solo b
        // 1 les gusta solo a 
        // 0 neutro de a y b
        // -1 neutro a 
        // -2 neutro b
        // -3 disgusta de a y b
        

        for (int i = 0; i < n; i++) {
            if (a[i] == 1 && b[i] == 1) c[i] = 3;

            else if (a[i] == 1 && b[i] != 1) c[i] = 1;
            else if (a[i] != 1 && b[i] == 1) c[i] = 2;

            else if (a[i] == -1 && b[i] == -1) c[i] = -3;
            
            else if (a[i] == 0 && b[i] == -1) c[i] = -1;
            else if (a[i] == -1 && b[i] == 0) c[i] = -2;
            
            else c[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            if (c[i] == 1) sumA++;
            else if (c[i] == 2) sumB++;
        }

        for(int i=0; i < n; i++) {
            if (c[i] == 3) {
                if (sumA < sumB) sumA++;
                else sumB++;
            }
        }
        for(int i=0; i < n; i++) {
            if (c[i] == -3) {
                if (sumA > sumB) sumA--;
                else sumB--;
            }
        }

        cout << min(sumA, sumB) << endl;
    }
    return 0;
}
