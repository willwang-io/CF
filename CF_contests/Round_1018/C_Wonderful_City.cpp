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

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<long long>> h(n, std::vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> h[i][j];
        }
    }
    std::vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int j = 0; j < n; ++j) {
        std::cin >> b[j];
    }
    std::vector<std::vector<bool>> r(n, std::vector<bool>(3)), c(n, std::vector<bool>(3));
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            long long d = h[i + 1][j] - h[i][j];
            if (std::abs(d) <= 1) {
                r[i][d + 1] = true;
            }
        }
    }
    for (int j = 0; j < n - 1; ++j) {
        for (int i = 0; i < n; ++i) {
            long long d = h[i][j + 1] - h[i][j];
            if (std::abs(d) <= 1) {
                c[j][d + 1] = true;
            }
        }
    }
    auto dp = [&](const std::vector<long long> &cost, const std::vector<std::vector<bool>> &yes) {
        long long memo[1001][2];
        std::memset(memo, -1, sizeof(memo));
        std::function<long long(int, int)> dfs = [&](int i, int u) -> long long {
            if (i == n) {
                return 0;
            }
            if (memo[i][u] != -1) {
                return memo[i][u];
            }
            long long ans = 1e18;
            for (int j = 0; j < 2; ++j) {
                if (i == 0 || !yes[i - 1][u - j + 1]) {
                    long long c = j * cost[i] + dfs(i + 1, j);
                    if (c < ans) {
                        ans = c;
                    }
                }
            }
            return memo[i][u] = ans;
        };
        return dfs(0, 0);
    };
    long long x = dp(a, r), y = dp(b, c);
    std::cout << (x >= 1e18 || y >= 1e18 ? -1 : x + y) << '\n';
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
