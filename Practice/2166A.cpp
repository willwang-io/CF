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
    std::string s;
    std::cin >> n >> s;
    int ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] != s[n - 1]) {
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