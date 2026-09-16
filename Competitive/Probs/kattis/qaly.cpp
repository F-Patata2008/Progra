#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vec vector

int main() {
    int n;
    cin >> n;
    double qaly;
    double años, cal;
    qaly = 0;
    for (int i = 0; i<n; i++) {
        cin >> cal >> años;
        qaly += cal*años;
    }
    cout << qaly << "\n";
    return 0;
}
