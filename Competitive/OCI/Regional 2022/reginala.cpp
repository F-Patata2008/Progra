#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string



int binarySearch(vector <int>& novec, int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (novec[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (novec[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}




int main() {
    int t;
    cin >> t;
    while (t--) {
        int no;
        cin >> no;
        vector <int> novec;
        int ussr;

        for (int x = 0; x < no; x++) {
            cin >> ussr;
            novec.push_back(ussr);
        }
        

        ll ini, fin;
        cin >> ini >> fin;

        cout << ini << " --- " << fin << endl;
        int outys = ini;


        for (int x = 0; x < fin;) {

            int n = sizeof(novec) / sizeof(novec[0]);
            int result = binarySearch(novec, 0, n - 1, outys);
            cout << "Vamos en: " << outys << endl;
            //this_thread::sleep_for(chrono::seconds(1));
            if (result != -1) {
                x++;
                outys+=ini;
            }
            else {
                outys+=ini;
            }

        }


        cout << outys << endl;
        cout <<  "------------------------" << endl;

 
    }
    return 0;
}



