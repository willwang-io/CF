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
    std::vector<int> d(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> d[i];
    }
    std::vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> l[i] >> r[i];
    }
    std::vector<int> low(n + 1), high(n + 1);
    low[0] = high[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int lo = low[i - 1], hi = high[i - 1];
        int mn = (d[i] == -1 ? lo : lo + d[i]);
        int mx = (d[i] == -1 ? hi + 1 : hi + d[i]);
        lo = std::max(mn, l[i]);
        hi = std::min(mx, r[i]);
        if (lo > hi) {
            std::cout << "-1\n";
            return;
        }
        low[i] = lo;
        high[i] = hi;
    }
    std::vector<int> h(n + 1);
    h[n] = low[n];
    for (int i = n; i >= 1; --i) {
        if (d[i] != -1) {
            h[i - 1] = h[i] - d[i];
        } else {
            int lo = low[i - 1], hi = high[i - 1];
            if (h[i] >= lo && h[i] <= hi) {
                d[i] = 0;
                h[i - 1] = h[i];
            } else {
                d[i] = 1;
                h[i - 1] = h[i] - 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << d[i] << ' ';
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
