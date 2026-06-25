#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define str string
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        str probs;
        cin >> probs;

        int sum = 0;
        map <char, bool> sol;

        for (char i : probs) {
            if (sol[i] == 1) {
                sum++;
            }
            else {
                sol[i] = 1;
                sum += 2;
            }
        }
       cout << sum << endl; 
    }
    return 0;
}
