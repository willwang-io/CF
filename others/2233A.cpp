#ifdef LOCAL
#include "../cp.hpp"
#else
#include <bits/stdc++.h>
#endif

void solve() {
    int n, x, y, z;
    std::cin >> n >> x >> y >> z;
    int ans = (n + x + y - 1) / (x + y), ai = 0;
    if (n <= x * z) {
        ai = (n + x - 1) / x;
    } else {
        ai = z + (n - x * z + x + 10 * y - 1) / (x + 10 * y);
    }
    std::cout << std::min(ans, ai) << '\n';
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