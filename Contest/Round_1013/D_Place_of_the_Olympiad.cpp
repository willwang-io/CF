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

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class...Args> void dbg_out(T &&x, Args&&...args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

/*
 * Created: Mar 25, 2025 @ 08:42:02
 * Author: will_wang
 */
void solve() {
    long long n, m, k;
    std::cin >> n >> m >> k;
    long long left = 1, right = 1e10;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long x = (m + 1) / (mid + 1);
        long long y = std::max(x * mid, m - x);
        if (n * y >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    std::cout << left << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        // std::cout << "Case #" << (i + 1) << ": ";
        solve();
    }
}
