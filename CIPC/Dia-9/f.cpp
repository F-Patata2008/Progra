#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n; 
    cin >> n;

    int cont = 0;
    vec <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vec <int> nose;
    set <int> esta;

    for (int i = n - 1; i >= 0; i--) {
        if (esta.find(a[i]) == esta.end()) {
            nose.push_back(a[i]);
            esta.insert(a[i]);
        }
    }
    reverse(nose.begin(), nose.end());


    cout << nose.size() << endl;
    for (int i = 0; i < nose.size(); i++) cout << nose[i] << (i == nose.size() - 1 ? "" : " ");
    cout << endl;
    


    return 0;
}
