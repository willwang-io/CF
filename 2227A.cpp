#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    int x, y;
    std::cin >> x >> y;
    if (x % 2 == 1 && y % 2 == 1) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
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