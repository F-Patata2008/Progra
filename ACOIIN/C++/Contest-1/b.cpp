#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int a, b;
    cin >> a >> b;
    queue <int> nums;
    
    int cont = 0;
    for (int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            cont++;
            nums.push(i);
        }
    }

    cout << cont << "\n";
    while (!nums.empty()){
        cout << nums.front() << " ";;
        nums.pop();
    }
    cout << endl;
    return 0;
}
