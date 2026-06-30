#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    int n, m;
    std::cin >> n >> m;
    int x1 = 100, y1 = 100, x2 = -1, y2 = -1;
    std::vector<std::string> g(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> g[i];
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '*') {
                x1 = std::min(x1, i);
                y1 = std::min(y1, j);
                x2 = std::max(x2, i);
                y2 = std::max(y2, j);
            }
        }
    }
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            std::cout << g[i][j];
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;

    while (t--) {
        solve();
    }
    return 0;
}