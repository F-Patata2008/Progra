#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int t;
    cin >> t;
    while (t--) {
        int largo;
        cin >> largo;
        int cont1 = 0;
        int cont2 = 0;

        int arr[largo];
        for (int i = 0; i < largo; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < largo-1; i++) {
            if (arr[i] == 0 && arr[i+1] == 0) {
                cont1++;
            }
            if (arr[i] == 1) {
                cont2 = cont1;
            }
        }
    }
    return 0;
}