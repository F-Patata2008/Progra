#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct attack {
  ll damage;
  ll cooldown;
};

ll dealt(ll t, ll c, ll d) {
  t = t - (t % c);
  return d + t * d / c;
}

ll att(vector<attack>& av, ll t) {
  ll sum = 0;
  for (attack& at : av) {
    sum += dealt(t, at.cooldown, at.damage);
  }
  return sum;
}

ll search(ll h, ll i, ll j, vector<attack>& av) {
  while (i < j) {
    ll m = (i + j) / 2;
    if (att(av, m) >= h) {
      j = m;
    } else {
      i = m + 1;
    }
  }
  return i;
}

void tc() {
  ll h, n;

  cin >> h >> n;

  vector<attack> a(n);

  for (int i = 0; i < n; i++) cin >> a[i].damage;
  for (int i = 0; i < n; i++) cin >> a[i].cooldown;

  ll j = 1;
  while (att(a, j) < h) {
    j *= 2;
  }
  cout << search(h, 0, j, a) + 1 << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    tc();
  }
}