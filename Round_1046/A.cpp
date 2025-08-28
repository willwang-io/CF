#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    auto ok = [](int x, int y) {
        return std::max(x, y) <= 2 * (std::min(x, y) + 1);
    };
    while (t--) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        if (ok(a, b) && ok(c - a, d - b)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}