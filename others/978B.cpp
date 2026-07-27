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
    std::string t;
    for (auto &c: s) {
        if (c == 'x' && t.size() >= 2 && t[t.size() - 1] == 'x' && t[t.size() - 2] == 'x') {
            continue;
        }
        t += c;
    }
    std::cout << s.size() - t.size() << '\n';
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