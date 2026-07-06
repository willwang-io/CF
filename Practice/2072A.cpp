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
    int n, k, p;
    std::cin >> n >> k >> p;
    k = std::abs(k);
    if (!k) {
        std::cout << "0\n";
        return;
    }
    if (p * n < k) {
        std::cout << "-1\n";
        return;
    }
    int tmp = k / p + (k % p == 0 ? 0 : 1);
    std::cout << std::min(tmp, n) << '\n';
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