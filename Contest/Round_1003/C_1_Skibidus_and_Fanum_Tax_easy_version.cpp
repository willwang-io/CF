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
 * Created: Feb 09, 2025 @ 08:42:05
 * Author: will_wang
 */
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (auto &x: a) {
        std::cin >> x;
    }
    int x;
    std::cin >> x;
    int prev = std::min(a[0], x - a[0]);
    for (int i = 1; i < n; ++i) {
        int u = a[i], v = x - a[i], ans = 1e9, ok = 0;
        if (u >= prev) {
            ans = std::min(ans, u);
            ok = 1;
        }
        if (v >= prev) {
            ans = std::min(ans, v);
            ok = 1;
        }
        if (!ok) {
            std::cout << "NO\n";
            return;
        }
        prev = ans;
    }
    std::cout << "YES\n";
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
