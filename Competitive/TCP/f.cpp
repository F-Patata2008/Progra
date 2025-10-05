#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct circle {
    ll x;
    ll y;
    ll min_distance;
};

int main() {
    ll n; cin >> n;
    vector<circle> circles(n);
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        circles[i] = circle { x, y, -1 };
    }
    int steps = 0;
    while (circles.size() > 1) {
        ll min_dist_sqr_step = LONG_LONG_MAX;
        for (int i = 0; i < circles.size(); i++) {
            ll min_dist_sqr_i = LONG_LONG_MAX;
            for (int j = 0; j < circles.size(); j++) {
                if (i == j) continue;
                ll dx = circles[i].x - circles[j].x;
                ll dy = circles[i].y - circles[j].y;
                ll dist_sqr = dx * dx + dy * dy;
                min_dist_sqr_i = min(dist_sqr, min_dist_sqr_i); 
            }
            circles[i].min_distance = min_dist_sqr_i;
            min_dist_sqr_step = min(min_dist_sqr_i, min_dist_sqr_step);
        }
        bool er = false;
        for (int i = circles.size() - 1; i >= 0; i--) {
            if (circles[i].min_distance == LONG_LONG_MAX)
                continue;
            if (circles[i].min_distance == min_dist_sqr_step) {
                if (!er) steps++;
                er = true;
                circles.erase(circles.begin() + i);
            }
        }
    };
    cout << steps << endl;
}