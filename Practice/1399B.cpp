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
    std::vector<int> a(n), b(n);
    int am = 1e9, bm = 1e9;
    for (auto &x: a) { 
        std::cin >> x;
        am = std::min(am, x);
    }
    for (auto &x: b) { 
        std::cin >> x;
        bm = std::min(bm, x);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > am && b[i] > bm) {
            int tmp = std::min(b[i] - bm, a[i] - am);
            ans += tmp;
            a[i] -= tmp;
            b[i] -= tmp;
        }
        if (a[i] > am) {
            ans += a[i] - am;
        }
        if (b[i] > bm) {
            ans += b[i] - bm;
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