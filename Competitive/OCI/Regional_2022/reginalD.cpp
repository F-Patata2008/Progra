#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
    int pajarracos, canastas;
    cin >> pajarracos >> canastas;

    int rojos = 0;
    int amarillos = 0;
    int canastas2 = 0;
    int canastas1 = 0;

    for (int x = 0; x < pajarracos; x++){
        int ussr;
        cin >> ussr;
        if (ussr == 1) rojos++;
        else if (ussr == 2) amarillos++;
    }

    for (int x = 0; x < canastas; x++) {
        int ussr;
        cin >> ussr;
        if (ussr == 1) canastas1++;
        else if (ussr == 2) canastas2++;
    }

    if ((amarillos >= canastas2) && (rojos >= canastas1)) {
        cout << "SI" << endl;
    }
    else if ((amarillos > canastas2) && ((amarillos - canastas2) >= (canastas1 - rojos))) {
        cout << "SI" << endl;
    }
    else if ((rojos > canastas1) && ((rojos - canastas1)/2 >= (canastas2-amarillos))) {
        cout << "SI" << endl;
    }
    else  cout << "NO" << endl;
    return 0;
}