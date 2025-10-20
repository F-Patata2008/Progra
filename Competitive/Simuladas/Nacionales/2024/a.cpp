#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    int n;
    cin >> n;


    vec <int> Part(n);
    for (int i = 0; i < n; i++) cin >> Part[i];

    bool elim = 1;
    int rondas = 0;

    while(true) {
        queue<int> el;
        rondas++;
        elim = 0;


        for (int i = 0; i < Part.size() - 1; i++) {
            if (Part[i] == -1 || Part[i + 1] == -1) continue;

            else if (Part[i + 1] >= Part[i]) {
                el.push(Part[i]);
                elim = 1;
            }

        }
        if (elim == false) {
            cout << rondas << endl;
            return 0;
        }
        Part.clear();
        while (!el.empty()) {
            Part.push_back(el.front());
            el.pop();
        }
    }

    return 0;
}
