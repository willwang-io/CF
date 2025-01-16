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
 * Created: Jan 15, 2025 @ 19:50:18
 * Author: will_wang
 */
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> d(n);
    for (auto &x: d) {
        std::cin >> x;
    }
    std::vector<int> a(n);
    a[0] = d[0];
    for (int i = 1; i < n; ++i) {
        int x = d[i] + a[i - 1];
        int y = a[i - 1] - d[i];
        if (x >= 0 && y >= 0 && x != y) {
            std::cout << -1 << '\n';
            return;
        }
        if (x >= 0) {
            a[i] = x;
        } else if (y >= 0) {
            a[i] = y;
        }
    }
    for (auto &x: a) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
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
