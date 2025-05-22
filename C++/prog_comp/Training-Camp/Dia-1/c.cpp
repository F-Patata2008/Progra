#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main() {
        str ussr;
        cin >> ussr;
        int n = ussr.size();

        stack<char> revisar;
        stack<char> otro;
    


        if (n %2 != 0) {
            cout << "No" << endl;
        }
        else {
            revisar.push(ussr[0]);
            for(int i = n-1; i > 0; i--) {
                otro.push(ussr[i]);
            }
            while (otro.size() != 0) {
                 if (revisar.size() == 0 || revisar.top() != otro.top()) {
                    revisar.push(otro.top());
                    otro.pop();
                }
                else if (revisar.top() == otro.top()) {
                    revisar.pop();
                    otro.pop();
                }
               
            }
            if (revisar.size() == 0) {
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
            
        }
        
    return 0;
}   