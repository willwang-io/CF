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
    int neg = 0, pos = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x == 1) {
            ++pos;
        } else {
            ++neg;
        }
    }
    int ans = 0;
    while (neg > pos) {
        ++pos;
        --neg;
        ++ans;
    }
    if (neg % 2 == 1) {
        ++ans;
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