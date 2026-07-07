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
    std::vector<int> a(n);
    int zero = 0, one = 0, sum = 0;
    for (auto &x: a) {
        std::cin >> x;
        if (x == 0) ++zero;
        else if (x == 1) ++one;
        else sum += x;
    }
    while (zero && one) {
        sum += 2;
        --zero;
        --one;
    }
    std::cout << sum + one + zero << '\n';
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