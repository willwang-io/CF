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
    std::string a, b;
    std::cin >> n >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i] - '0', y = b[i] - '0';
        int z = std::abs(x - y);
        ans += std::min(z, 10 - z); 
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;

    while (t--) {
        solve();
    }

    return 0;
}