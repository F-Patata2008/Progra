#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define str string
#define vec vector

int main() {
    ll tam, obj;
    cin >> tam >> obj;

    map<int,int> arr;
    map<int,int> map;
    bool si = 0;
   
    for(int i = 0; i < tam; i++) {
        int ussr;
        cin >> ussr;
        arr[ussr] = i;
        map[i] = ussr;
    }
    int calc;
    int out, ot;

    for ( int i = 0; i < tam; i++) {
        calc = map[i];
        if (arr.find(obj-calc) != arr.end() && (*arr.find(obj-calc)).second != i) {
            si = 1;
            out = (*arr.find(obj-calc)).second;
            ot = i;
            break;
        }
    }
    if (si) {
        cout << ot+1 << " " << out+1 << endl;

    }
    else cout << "-1" << endl;



    return 0;
}