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
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), one(n + 1), three(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        one[i] = one[i - 1] + (a[i] == 1 ? 1 : -1);
        three[i] = three[i - 1] + (a[i] == 3 ? -1 : 1);
    }
    int mn = 1e9;
    for (int i = 2; i <= n - 1; ++i) {
        if (one[i - 1] >= 0) {
            mn = std::min(mn, three[i - 1]);
        }
        if (mn <= three[i]) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
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