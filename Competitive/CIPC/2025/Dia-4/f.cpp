#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

vec<int> mem;
int a,b,c;


int main() {
    int largo;
    cin >> largo;
    mem.assign(largo+1,-1e9);
    cin >> a >> b >> c;
    mem[0] = 0;

    for (int i = 1; i <= largo; i++) {
        if (i - a >= 0) mem[i] = max(mem[i], mem[i - a] + 1);
        if (i - b >= 0) mem[i] = max(mem[i], mem[i - b] + 1);
        if (i - c >= 0) mem[i] = max(mem[i], mem[i - c] + 1);
    }
    cout << mem[largo] << endl;
   
   
   
   return 0;
}
