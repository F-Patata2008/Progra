#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

int main() {
    int arr[14] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    int n;
    cin >> n;
    bool si = 0;

    for (int x: arr) { 
        if (n % x == 0) {
            si = 1;
        }
    }
    if (si) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}