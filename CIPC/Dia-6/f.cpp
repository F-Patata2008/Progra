#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define vec vector
// 0 inicio
// 1 norte
// 2 este
// 3 sur 
// 4 oeste

vec <vec <bool>> check;

void dfs(int i, int j, int t) {	
	check[i][j] = 0;
	for(int k = 1; k <= 4; k++) {
		if(k == t) continue;
		else if(k == 1) {
			for(int l = j; l <= 1000; l++) {
				if(check[i][l]) {
					dfs(i, l, 3);
					break;
				}
			}
		}
		else if(k == 2) {
			for(int l = i; l <= 1000; l++) {
				if(check[l][j]) {
					dfs(l, j, 4);
					break;
				}
			}
		}
		else if(k == 3) {			
			for(int l = j; l >= 0; l--) {
				if(check[i][l]) {
					dfs(i, l, 1);
					break;
				}
			}			
		}
		else {
			for(int l = i; l >= 0; l--) {
				if(check[l][j]) {
					dfs(l, j, 2);
					break;
				}
			}	
		}
	}
}

int main() {
	int n;
	cin >> n;
    check.assign(1005, vec <bool> (1005, 0));

	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		check[x][y] = 1;
	}

	int g = 0;
	for(int i = 1; i <= 1000; i++) {
		for(int j = 1; j <= 1000; j++) {
			if(check[i][j]) {
				dfs(i, j, 0);
				g++;
			}
		}
	}
	cout << g - 1 << endl;
	return 0;
} 
