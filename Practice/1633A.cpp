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
    auto s = std::to_string(n);
    std::string ans;
    int mn_diff = 100;
    for (int i = 0; i * 7 <= 1000; ++i) {
        auto t = std::to_string(i * 7);
        if (t.size() != s.size()) {
            continue;
        }
        int diff = 0;
        for (int j = 0; j < t.size(); ++j) {
            if (s[j] != t[j]) {
                ++diff;
            }
        }
        if (diff < mn_diff) {
            mn_diff = diff;
            ans = t;
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