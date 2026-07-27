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
 * Created: Feb 09, 2025 @ 09:57:25
 * Author: will_wang
 */
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<long long, std::vector<long long>>> a(n);
    for (int i = 0; i < n; ++i) {
        long long total = 0;
        std::vector<long long> tmp(m);
        for (int j = 0; j < m; ++j) {
            std::cin >> tmp[j];
            total += tmp[j];
        }
        a[i] = std::make_pair(total, tmp);
    }
    std::sort(a.begin(), a.end(), [&](const auto &x, const auto &y) { return x.first > y.first; });
    long long ans = 0LL, pre = 0LL;
    for (auto &p: a) {
        for (auto &x: p.second) {
            pre += x;
            ans += pre;
        }
    }
    std::cout << ans <<'\n';
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
