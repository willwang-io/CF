#ifdef LOCAL
#include "../cp.hpp"
#else
#include <bits/stdc++.h>
#endif

void solve() {
    int n;
    std::cin >> n;
    int mx = 0, mn = 7;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        mx = std::max(mx, x);
        mn = std::min(mn, x);
    }
    std::cout << mx + 1 - mn << '\n';
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