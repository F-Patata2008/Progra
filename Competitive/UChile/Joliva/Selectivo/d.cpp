#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n = 69;


    unsigned long long dp[ 67 ][ 67 ];

    for (int i = 0; i < n; i++) {
        dp[ i ][ 0 ] = 1;
        dp[ 0 ][ i ] = 1;
    }


    dp[ 0 ][ 0 ] = 0;
    dp[ 33 ][ 33 ] = 0;

    for (int i = 0; i < 67; i++) {
        for (int j = 0; j < 67; j++) {
            if (i == 0 && j == 0)
                continue;
            else if (i == 33 && j == 33)
                continue;
            else
                dp[ i ][ j ] = dp[ i - 1 ][ j ] + dp[ i ][ j - 1 ];
        }
    }
    cout << dp[ 66 ][ 66 ] << endl;


    return 0;
}


// 1981141128
// 1927676956167753864
// 10118423589045665792
// 5850032141924040704
//
