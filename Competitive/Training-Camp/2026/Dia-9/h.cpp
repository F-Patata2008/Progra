#include <bits/stdc++.h>
#include "torneo.h"
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector


pair<int, int> top_2_inversiones(int n) {
    int c, sc;
    vec<int> jugadores (n);
    for (int i = 0; i < n; i++) jugadores[i] = i + 1;

    vec<vec<int>> historial (n + 1);
    while(jugadores.size() > 1) {
        vec<int> ronda;

        if (jugadores.size() % 2 == 1) {
            for (int i = 0; i < jugadores.size() - 2; i += 2) {
                int j1 = jugadores[i];
                int j2 = jugadores[i + 1];

                if (ganador(j1, j2)) {
                    ronda.push_back(j1);
                    historial[j1].push_back(j2);
                }
                else {
                    ronda.push_back(j2);
                    historial[j2].push_back(j1);
                }
            }
            ronda.push_back(jugadores[jugadores.size() - 1]);
        }
        else {
            for (int i = 0; i < jugadores.size() - 1; i += 2) {
                int j1 = jugadores[i];
                int j2 = jugadores[i + 1];

                if (ganador(j1, j2)) {
                    ronda.push_back(j1);
                    historial[j1].push_back(j2);
                }
                else {
                    ronda.push_back(j2);
                    historial[j2].push_back(j1);
                }
            }
        }
        jugadores = ronda;

    }

    c = jugadores[0];
    vec<int> rivales = historial[c];

    sc = rivales[0];
    for (int i = 1; i < rivales.size(); i++) {
        if (!ganador(sc, rivales[i])) sc = rivales[i];
    }

    return {c, sc};
}
