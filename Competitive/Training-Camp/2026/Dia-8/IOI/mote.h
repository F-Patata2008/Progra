#include <vector>
#include <iostream>
using namespace std;

int indice_malo = -1, nro_llamadas = 0, nro_pruebas = 0, n;
bool fail = false;
const int MAX_PRUEBAS = 1000;

int mote_con_huesito(int n);

vector<bool> laboratorio(vector<vector<int>> pruebas) {
  nro_llamadas++;
  nro_pruebas = pruebas.size();

  if(nro_llamadas > 1 || nro_pruebas > MAX_PRUEBAS) {
    fail = true;
    return {};
  }

  vector<bool> ans(nro_pruebas, false);

  for(int i = 0; i < nro_pruebas; ++i) {
    for(int x : pruebas[i]) {
      if(x < 1 || x > n) {
        fail = true;
        return {};
      }

      if(x == indice_malo) {
        ans[i] = true;
      }
    }
      
  }

  return ans;
}

int main() {
    
    cin >> n >> indice_malo;

    int indice = mote_con_huesito(n);

    if (indice != indice_malo) {
        cout << "Incorrecto. Se encontró el índice malo " << indice << " en lugar de " << indice_malo << "." << endl;
    }else if(fail) {
        cout << "Incorrecto. Se llamó a laboratorio de forma incorrecta." << endl;
    } else {
        cout << "Correcto. Se encontró el índice malo " << indice_malo << "." << endl;
    }
    return 0;
}

