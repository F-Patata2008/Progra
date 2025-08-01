#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector


bool compa(const pair<int, int>& s1, const pair<int, int>& s2) {
    return s1.second > s2.second;
}


int main() {
    int n, k;
    cin >> n >> k;

    vec <pair <int, int>> canc(n);
    for (int i = 0; i < n; i++) cin >> canc[i].first >> canc[i].second;

    sort(canc.begin(), canc.end(), compa);
    ll act = 0;
    ll maxi = 0;

    priority_queue<int, vec <int>, greater <int>> pq;

    for (int i = 0; i < n; i++) {
        act += canc[i].first;
        pq.push(canc[i].first);

        if (pq.size() > k) {
            act -= pq.top();
            pq.pop();
        }
        maxi = max(maxi, act * canc[i].second);
    }
    cout << maxi << endl;

    return 0;
}
