#include <bits/stdc++.h>
#include <deque>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n, k;
    cin >> n >> k;
    
    vec <int> id(n);
    for (int i = 0; i < n; i++) cin >> id[i];
    
    deque <int> pant;
    set <int> in;

    for (int i = 0; i < n; i++) {
        if (in.find(id[i]) == in.end()) {
            if (in.size() == k) {
                int del = pant.back();
                pant.pop_back();
                in.erase(del);
            }
            pant.push_front(id[i]);
            in.insert(id[i]);
        }
    }
    cout << in.size() << "\n";
    while (!pant.empty()) {
        cout << pant.front() << " ";
        pant.pop_front();
    }

    return 0;
}

