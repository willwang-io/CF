#ifdef LOCAL
#include "../cp.hpp"
#else
#include <bits/stdc++.h>
#endif

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        int ans = 0, cur_min = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            cur_min = std::min(x, cur_min);
            ans += cur_min;
        }
        std::cout << ans << '\n';
    }
}