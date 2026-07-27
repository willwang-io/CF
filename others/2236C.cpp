#ifdef LOCAL
#include "../cp.hpp"
#else
#include <bits/stdc++.h>
#endif

void solve() {
    long long a, b, x;
    std::cin >> a >> b >> x;

    std::vector<std::pair<long long, int>> va, vb;

    for (int i = 0;; ++i) {
        va.push_back({a, i});
        if (a == 0) {
            break;
        }
        a /= x;
    }
    for (int i = 0;; ++i) {
        vb.push_back({b, i});
        if (b == 0) {
            break;
        }
        b /= x;
    }

    long long ans = __LONG_LONG_MAX__;
    for (auto &p: va) {
        for (auto &q: vb) {
            ans = std::min(ans, p.second + q.second + std::abs(p.first - q.first));
        }
    }
    std::cout << ans << '\n';
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