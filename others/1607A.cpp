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
    std::string s, t;
    std::cin >> s >> t;
    std::vector<int> a(26);
    for (int i = 0; i < 26; ++i) {
        a[s[i] - 'a'] = i;
    }
    int ans = 0;
    for (int i = 1; i < t.size(); ++i) {
        ans += std::abs(a[t[i] - 'a'] - a[t[i - 1] - 'a']);
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