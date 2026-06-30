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
 * Created: Feb 09, 2025 @ 08:47:53
 * Author: will_wang
 */
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (auto &x: a) {
        std::cin >> x;
    }
    for (auto &x: b) {
        std::cin >> x;
    }
    std::sort(b.begin(), b.end());
    long long cur = -1e18;
    for (int i = 0; i < n; ++i) {
        long long keep = (a[i] >= cur ? a[i] : 1e18);
        auto it = std::lower_bound(b.begin(), b.end(), cur + a[i]);
        long long change = (it == b.end() ? 1e18 : (*it) - a[i]);

        long long choice = std::min(keep, change);
        if (choice == 1e18) {
            std::cout << "NO\n";
            return;
        }
        cur = choice;
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
