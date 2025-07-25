#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int a;
    queue <int> cor;
    cin >> a;

    int b;
    for (int i = 0; i < 3; i++) {
        cin >> b;
        cor.push(b);
    }

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        b = cor.front();
        cor.pop();
        if (a < b) sum++;
    }
    cout << sum << endl;
  }
  return 0;
}
