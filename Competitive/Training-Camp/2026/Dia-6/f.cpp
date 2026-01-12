#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Probamos todas las máscaras desde 0 hasta 2^n - 1
    // (1 << n) es lo mismo que 2 elevado a n
    for (int mask = 0; mask < (1 << n); mask++) {
        
        string p = "";      // Subsecuencia a extraer
        string x = "";      // Lo que queda
        vector<int> indices_p; // Para guardar los índices (1-based)

        for (int i = 0; i < n; i++) {
            // Revisamos si el bit i está encendido en la máscara
            // (mask >> i) & 1  verifica el i-ésimo bit
            if ((mask >> i) & 1) {
                p += s[i];
                indices_p.push_back(i + 1); // Guardamos índice + 1
            } else {
                x += s[i];
            }
        }

        // Condición 1: p debe ser no-decreciente (sorted)
        // Como es binario, significa que no puede haber un '0' después de un '1'
        bool p_sorted = true;
        for (int i = 0; i + 1 < p.size(); i++) {
            if (p[i] > p[i+1]) {
                p_sorted = false;
                break;
            }
        }
        // Alternativa moderna: is_sorted(p.begin(), p.end())

        // Condición 2: x debe ser palíndromo
        bool x_palindrome = true;
        for (int i = 0; i < x.size() / 2; i++) {
            if (x[i] != x[x.size() - 1 - i]) {
                x_palindrome = false;
                break;
            }
        }

        // Si cumple ambas condiciones, imprimimos y terminamos este caso
        if (p_sorted && x_palindrome) {
            cout << indices_p.size() << "\n";
            for (int i = 0; i < indices_p.size(); i++) {
                cout << indices_p[i] << (i == indices_p.size() - 1 ? "" : " ");
            }
            cout << "\n";
            return; // Encontramos una solución, salimos de la función solve()
        }
    }

    // Si probamos todo y nada funcionó (aunque el problema garantiza solución o -1)
    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
