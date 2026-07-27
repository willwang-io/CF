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
 * Created: Mar 22, 2025 @ 08:36:30
 * Author: will_wang
 */
long long x, y;
static long long dp[100][2][2];
static bool seen[100][2][2];

long long f(int i, int a, int b){
    if (i == 62)
        return (a == 0 && b == 0) ? 0LL : -1LL;

    if (seen[i][a][b]) {
        return dp[i][a][b];
    }
    long long ans = -1, bx = (x >> i) & 1, by = (y >> i) & 1;
    for (int d = 0; d < 2; ++d) {
        int sum_x = bx + d + a;
        int ax = sum_x & 1, bx = sum_x >> 1;

        int sum_y = by + d + b;
        int ay = sum_y & 1, by = sum_y >> 1;

        if (ax && ay) {
            continue;
        }
        long long tmp = f(i + 1, bx, by);
        if (tmp == -1) {
            continue;
        }
        ans = tmp + ((long long) d << i);
        break;
    }
    seen[i][a][b] = true;
    return dp[i][a][b] = ans;
};

void solve() {
    std::cin >> x >> y;
    if (x == y) {
        std::cout << -1 << "\n";
        return;
    }
    std::memset(seen, false, sizeof seen);
    std::cout << f(0, 0, 0) << '\n';
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
