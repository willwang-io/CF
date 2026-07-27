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
    int n, x;
    std::cin >> n >> x;
    bool used = false, ok = true;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        if (a == 1) {
            if (!used) {
                used = true;
            } 
            if (x <= 0) {
                ok = false;
            }
        }
        if (used) {
            --x;
        }
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