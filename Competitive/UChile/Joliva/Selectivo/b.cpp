#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;

    int ussr;
    priority_queue<int> queque;
    for (int i = 0; i < n; i++) {
        cin >> ussr;
        queque.push(ussr);
    }
    int cont = 0;
    ll A = 0, B = 0;
    while (!queque.empty()) {
        if (cont % 2 == 0) {
            A += queque.top();
        } else {
            B += queque.top();
        }
        queque.pop();
        cont++;
    }

    cout << A << endl << B << endl;

    return 0;
}
