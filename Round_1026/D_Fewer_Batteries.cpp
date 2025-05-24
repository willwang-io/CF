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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];
    }
    std::vector<std::vector<std::pair<int,int>>> edges(n + 1);
    for (int i = 0; i < m; ++i) {
        int s, t, w;
        std::cin >> s >> t >> w;
        edges[s].emplace_back(t, w);
    }
    if (n == 1) {
        std::cout << "0\n";
        return;
    }
    auto ok = [&](int mid) {
        std::vector<int> a(n + 1, -1);
        a[1] = b[1] <= mid ? b[1] : mid;
        for (int v = 1; v <= n; ++v) {
            if (a[v] >= 0) {
                int x = a[v];
                for (const auto &pr: edges[v]) {
                    int u = pr.first, w = pr.second;
                    if (w <= mid && x >= w) {
                        int y = x + b[u];
                        if (y > mid) {
                            y = mid;
                        }
                        if (y > a[u]) {
                            a[u] = y;
                        }
                    }
                }
            }
        }
        return a[n] >= 0;
    };
    int lo = 0, hi = 1e9, ans = -1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (ok(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    std::cout << (ans >= 0 ? ans : -1) << '\n';
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
