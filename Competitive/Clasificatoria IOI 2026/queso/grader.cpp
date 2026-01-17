#include <set>
#include <stdlib.h>
#include <iostream>
#include "queso.h"

using namespace std;

int N;
const int max_queries = 64;
int queries = 0;
int anterior = -1;
set<int> usados;
bool repetido = false;
bool fuera_de_rango = false;

int C;

bool alumnos_notan_cambio(int p){
    queries++;
    if(queries > max_queries) return false;
    if(usados.count(p)){
        repetido = true;
        return false;
    }
    if(p < 1 || p > N){
        fuera_de_rango = true;
        return false;
    }

    bool respuesta = false;
    if(anterior != -1){
        respuesta = (abs(p - anterior) >= C);
    }
    
    usados.insert(p);
    anterior = p;
    return respuesta;
}

int main(){

    cin >> N >> C;

    if(N <= 1 || C <= 0 || C > N){
        cout << "Input invalido" << endl;
        return 0;
    }

    int resultado = encontrar_C(N);

    if(repetido){
        cout << "Incorrecto: se llamo a alumnos_notan_cambio con un mismo parametro mas de una vez" << endl;
        return 0;
    }
    if(queries > max_queries){
        cout << "Incorrecto: se llamo a alumnos_notan_cambio mas de " << max_queries << " veces" << endl;
        return 0;
    }
    if(resultado != C){
        cout << "Incorrecto: el valor devuelto es " << resultado << " pero el correcto es " << C << endl;
        return 0;
    }
    if(fuera_de_rango){
        cout << "Incorrecto: se llamo a alumnos_notan_cambio con un parametro fuera de rango" << endl;
        return 0;
    }

    cout << "Correcto" << endl;
}