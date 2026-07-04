#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

void solve() {
    int x, y;
    std::cin >> x >> y;
    if (x == y) { std::cout << "0\n"; return; }
    if (y > x && (y - x) % 2 != 0) {
        std::cout << "1\n";
        return;
    }
    if (y < x && (x - y) % 2 == 0) {
        std::cout << "1\n";
        return;
    } 
    std::cout << "2\n";
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