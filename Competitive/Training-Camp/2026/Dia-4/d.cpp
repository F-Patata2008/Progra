#include <bits/stdc++.h>
#include <istream>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

vec<ll> a;
ll n;

vec<ll> disMIzq;
vec<ll> disMDer;
vec<ll> dismIzq;
vec<ll> dismDer;

void izq(){
    stack<pair<ll, ll>> mayor, menor;
    for (int i = 0; i < n; i++) {
        while (!mayor.empty() && mayor.top().first < a[i]) mayor.pop();
        if (mayor.empty()) {
            mayor.push({a[i], i});
            disMIzq[i] = -1;
        }

        else {
            disMIzq[i] = mayor.top().second;
            mayor.push({a[i],i});
        }
    }
    for (int i = 0; i < n; i++) {
        while (!menor.empty() && menor.top().first > a[i]) menor.pop();
        if (menor.empty()) {
            menor.push({a[i], i});
            dismIzq[i] = -1;
        }
        else {
            dismIzq[i] = menor.top().second;
            menor.push({a[i],i});
        }
    }

}

void der(){
    stack<pair<ll, ll>> mayor, menor;
    for (int i = n - 1; i >= 0; i--) {
        while (!mayor.empty() && mayor.top().first <= a[i]) mayor.pop();
        if (mayor.empty()) {
            mayor.push({a[i], i});
            disMDer[i] = n;
        }

        else {
            disMDer[i] = mayor.top().second;
            mayor.push({a[i],i});
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!menor.empty() && menor.top().first >= a[i]) menor.pop();
        if (menor.empty()) {
            menor.push({a[i], i});
            dismDer[i] = n;
        }
        else {
            dismDer[i] = menor.top().second;
            menor.push({a[i],i});
        }
    }

}




int main() {
    cin >> n;
    ll maxs = 0;
    ll mins = 0;

    disMIzq.assign(n, -1);
    disMDer.assign(n, -1);
    dismIzq.assign(n, -1);
    dismDer.assign(n, -1);

    a.assign(n,-1);
    for (int i = 0; i < n; i++) cin >> a[i];

    izq();
    der();

    for (int i = 0; i < n; i++) {
        ll d1, d2;
        d1 = i - disMIzq[i];
        d2 = disMDer[i] - i;
        maxs += (ll) d1 * d2 * a[i];
    }

    for (int i = 0; i < n; i++) {
        ll d1, d2;
        d1 = i - dismIzq[i];
        d2 = dismDer[i] - i;
        mins += (ll) d1 * d2 * a[i];
    }

    ll total = maxs - mins;
    cout << total << endl;

    return 0;
}
