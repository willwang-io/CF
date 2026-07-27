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
    int cnt = 0;
    for (auto &x: s) {
        if (x == '(') {
            ++cnt;
        } else {
            --cnt;
        }
    }
    std::cout << (cnt == 0 ? "YES\n" : "NO\n");
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