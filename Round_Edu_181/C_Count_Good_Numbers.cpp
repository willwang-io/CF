#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <ranges>
#include <vector>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

long long f(long long n) {
    if (n <= 0) {
        return 0;
    }
    long long ans = n;
    const int p[] = {2, 3, 5, 7};
    for (int mask = 1; mask < (1 << 4); ++mask) {
        long long prod = 1;
        int bits = __builtin_popcount(mask);
        for (int i = 0; i < 4; ++i) {
            if (mask & (1 << i)) {
                prod *= p[i];
            }
        }
        if (bits % 2 == 1) {
            ans -= n / prod;
        } else {
            ans += n / prod;
        }
    }
    return ans;
}

void solve() {
    long long l, r;
    std::cin >> l >> r;
    std::cout << f(r) - f(l - 1) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}
