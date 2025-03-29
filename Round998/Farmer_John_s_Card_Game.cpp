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
 * Created: Jan 19, 2025 @ 08:44:21
 * Author: will_wang
 */
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }
    for (auto &x: a) {
        std::sort(x.begin(), x.end());
    }
    std::vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        if (a[i][0] < 0 || a[i][0] >= n) {
            std::cout << -1 << '\n';
            return;
        }
        order[a[i][0]] = i;
    }
    int prev = -1;
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (a[order[i]][j] - 1 != prev) {
                std::cout << -1 << '\n';
                return;
            }
            prev = a[order[i]][j];
        }
    }
    for (auto &x: order) {
        std::cout << x + 1 << ' ';
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

