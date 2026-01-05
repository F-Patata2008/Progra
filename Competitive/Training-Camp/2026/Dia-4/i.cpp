#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int SNICKERS;
    cin >> SNICKERS;

    vector<int> row(SNICKERS), row1(SNICKERS);

    for(int a = 0; a < SNICKERS; a++) {
        cin >> row[a];
    }

    for(int b = 0; b < SNICKERS; b++) {
        cin >> row1[b];
    }

    vector<ll> dp(SNICKERS), dp1(SNICKERS);
    dp[0] = row[0];
    dp1[0] = row1[0];



    for(int i = 1; i < SNICKERS; i++) {
        dp[i] = max(dp[i -1], dp1[i - 1] + row[i]);
        dp1[i] = max(dp1[i -1], dp[i - 1] + row1[i]);
    }

    cout << max(dp[SNICKERS - 1], dp1[SNICKERS - 1]) << endl;

  
 return 0; 
}
