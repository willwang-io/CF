#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    int gold = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x >= k) {
            gold += x;
        }
        if (!x && gold) {
            --gold;
            ++ans;
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