#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int x = -1, y = -1, side = 0;
    for (int i = 0; i < 4; ++i) {
        int cx, cy;
        std::cin >> cx >> cy;
        if (cx == x) {
            side = std::abs(cy - y);
        }
        if (x == -1) {
            x = cx;
            y = cy;
        }
    }
    std::cout << side * side << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}