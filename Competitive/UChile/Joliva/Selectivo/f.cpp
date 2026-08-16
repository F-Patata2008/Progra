#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int ini = 2;
    cout << "67 1 3 2 ";
    for (int i = 3; i < 67; i++) {

        if (i % 2 == 1) {
            ini += 3;
        } else if (i % 2 == 0) {
            ini--;
        }


        cout << ini << " ";
    }

    cout << endl;
    return 0;
}

// 3 1 2
