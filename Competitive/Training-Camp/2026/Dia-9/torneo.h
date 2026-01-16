#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector


bool ganador (int i, int j) {
    if (i < j) return true;
    else return false;
}
pair<int, int> top_2_inversiones (int n);

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    pair<int, int> z = top_2_inversiones(n);

    cout << z.first << " " << z.second << endl;
    return 0;
}
