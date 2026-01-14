#include <bits/stdc++.h>
#include "mote.h"
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector


int mote_con_huesito (int n) {
    vec<vec<int>> probs;
    for (int i = 0; (1<<i) <= n; i++) {
        vec <int> patata;
        for (int j = 1; j <= n; j++) {
            if (j & (1<<i)) patata.push_back(j);
        }
        probs.push_back(patata);
    }
    vec<bool> pos = laboratorio(probs);

    int hueso = 0;
    for (int i = 0; i < pos.size(); i++) {
        if (pos[i]) hueso |= (1<<i);
    }

    return hueso ;
}
