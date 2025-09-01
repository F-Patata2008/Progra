/*#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

const int max_n = 1e6;
ll mem[max_n];

ll fib(int N) {
    if (N <= 1) {
        return 1;
    }
    if (mem[N] != 0) {
        return  mem[N];
    }
    mem[N] = fib(N-1) + fib(N-2);
    return mem[N];
}

int main() {
    int t;
    cin >> t;
    cout << fib(t);
    return 0;
}
*/



#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;               // Base cases
    vector<int> dp(n + 1);              // Tabulation table
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl;
    return 0;
}
