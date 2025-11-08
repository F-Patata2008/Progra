#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> mont(n);
    int z = n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mont[x]=z;
        z--;
    }

    
}