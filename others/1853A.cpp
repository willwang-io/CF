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
    std::vector<int> a(n);
    int diff = 1e9;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (i == 0) {
            continue;
        }
        diff = std::min(diff, a[i] - a[i - 1]);
        ok &= a[i] >= a[i - 1];
    }
    if (!ok) {
        std::cout << "0\n";
    } else {
        std::cout << diff / 2 + 1 << '\n';
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