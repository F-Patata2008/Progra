#include <bits/stdc++.h>
#include <cctype>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

int main() {
    str ussr;
    cout << "Ingrese el correo a crear:" << endl;
    cin >> ussr;
    
    str usr = ussr.substr(0, ussr.find('@'));
    str dom = ussr.substr(ussr.find('@') + 1, ussr.find('.') - ussr.find('@') - 1);
    str subdom = ussr.substr(ussr.find('.') + 1);

    bool letras = 1;

    for (char p : usr) {
        if (!isalpha(p)) letras = 0;
    }

    vec <str> sub = {"cl", "ar", "co", "br", "uy"};
    auto it = find(sub.begin(), sub.end(),subdom);

    if (letras && dom == "util" && it != sub.end() ) {
        cout << "Paso el primer check" << endl;
    }
    else {
        cout << "Su correo presenta los siguinetes errores:" << endl;
        if (!letras) printf("- Solo use Letras\n");
        if (dom != "util") printf("- Dominio malo, use @util.<subdominio>\n");
        if (it == sub.end()) printf("- SubDominio malo, use .cl, .br, .ar, .uy o .co\n");
    }


    return 0;
}
