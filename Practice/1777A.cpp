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
    std::vector<int> a;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        x %= 2;
        if (a.empty() || a.back() ^ x == 1) {
            a.push_back(x);
        } else {
            int y = a.back();
            a.pop_back();
            a.push_back(x * y);
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