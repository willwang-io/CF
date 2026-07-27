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
    int k;
    std::cin >> k;
    int cnt = 0;
    bool ok = false;
    for (int i = 0; i < k; ++i) {
        int c;
        std::cin >> c;
        if (c >= 3) {
            ok = true;
        }
        if (c >= 2) {
            ++cnt;
        }
    }
    if (cnt >= 2) {
        ok = true;
    }
    std::cout << (ok ? "YES\n" : "NO\n");
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