#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <cmath>

using ll = long long;

struct Point {
    int x, y;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<Point> pts(n);
    for (auto &pt: pts) {
        std::cin >> pt.x >> pt.y;
    }
    std::sort(pts.begin(), pts.end(), [](const Point &p1, const Point &p2) {
        if (p1.x == p2.x) {
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    });
    std::string ans;
    int x = 0, y = 0, max_y = pts[0].y;
    for (int i = 0; i < n; ++i) {
        if (pts[i].y < y) {
            std::cout << "NO\n";
            return;
        }
        ans += std::string(pts[i].x - x, 'R') + std::string(pts[i].y - y, 'U');
        x = pts[i].x;
        y = pts[i].y;
    }
    std::cout << "YES\n";
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }
}