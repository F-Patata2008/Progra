#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    str papa;
    cin >> papa;

    int conce = 0;
    for (int i = 0; i < papa.size() - 1; i++) {
        if (papa[i] == papa[i + 1]) conce++;
        else conce = 0;

        if (conce >= 6) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
