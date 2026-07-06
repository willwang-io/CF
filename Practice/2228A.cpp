#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using ll = long long;

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

void solve() {
    int n;
    std::cin >> n;
    int cnt[3] = {};
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        ++cnt[x];
    }
    int tmp = std::min(cnt[1], cnt[2]);
    cnt[1] -= tmp;
    cnt[2] -= tmp;
    std::cout << cnt[0] + tmp + cnt[1] / 3 + cnt[2] / 3 << '\n';
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