#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;

    vec<pair<int, int>> mem(n); //Boy in mem[i].first, girl in mem[i].second

    for (int i = 0; i < n; i++) cin >> mem[i].first >> mem[i].second;



    return 0;
}
