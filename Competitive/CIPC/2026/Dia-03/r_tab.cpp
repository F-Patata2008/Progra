#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector

struct SegmentTree {
  int n;
  vec<ll> Tree;

  SegmentTree(vec<ll> &a) {
    n = (int)a.size();
    Tree.resize(4 * n);
    build(a, 0, 0, n - 1);
  }

  void build(vec<ll> &a, int nodo, int izq, int der) {
    if (izq == der) {
      Tree[nodo] = a[izq];
      return;
    }
    int mid = izq + (der - izq) / 2;
    build(a, 2 * nodo + 1, izq, mid);
    build(a, 2 * nodo + 2, mid + 1, der);
    Tree[nodo] = max(Tree[2 * nodo + 1], Tree[2 * nodo + 2]);
  }

  = izq + (der - izq) / 2;
  return max(query(2 * nodo + 1, izq, mid, l, r),
             query(2 * nodo + 2, mid + 1, der, l, r));
}
}
;

vec<ll> prefix_function(const str &s) {
  int n = (int)s.size();
  vec<ll> pi(n, 0);
  for (int i = 1; i < n; i++) {
        int j = ( while] != s]) j = (int)pi[j - 1];
        if (s[i] == s[j])
          j++;
        pi[i] = j;
  }
  return pi;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  str ussr;
  cin >> ussr;
  int n = (int)ussr.size();

  vec<ll> patata = prefix_function(ussr);
  SegmentTree busc(patata);

  if (patata[n - 1] == 0) {
    cout << "Just a legend\n";
    return 0;
  }

  for (int i = (int)patata[n - 1]; i > 0; i = (int)patata[i - 1]) {
    if (busc.q(0, n - 2) >= i) {
      cout << ussr.substr(0, i) << '\n';
      return 0;
    }
  }

  cout << "Just a legend\n";
  return 0;
}
