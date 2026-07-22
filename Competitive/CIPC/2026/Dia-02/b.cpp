#include <bits/stdc++.h>
#include <cctype>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        str ussr;
        cin >> ussr;

        int sum = 0;

        map<char,int> freq;
        for (char c : ussr) freq[c]++;
        int s = 0;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            char act = it->first;
            if (islower(act)) {
                if (freq.find(act - 32) != freq.end()) {
                    int dif = min(freq[act - 32], it->second);
                    sum += dif;
                    freq[act] -= dif;
                    freq[act - 32] -= dif;
                }
            }
            else if (isupper(act)) {
                if (freq.find(act + 32) != freq.end()) {
                    int dif = min(freq[act + 32], it->second);
                    sum += dif;
                    freq[act] -= dif;
                    freq[act + 32] -= dif;
                }

            }
        }
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            if (k == 0) break;
            char act = it->first;
            while (it->second >= 2 && k > 0) {
                k--;
                freq[act] -= 2;
                sum++;
            }
        }

        cout << sum << endl;

    }
    return 0;
}
