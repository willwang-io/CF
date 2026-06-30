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
    std::vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::vector<long long> pref(n + 1), suf(n + 2);
    pref[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        pref[i] = std::max(a[i], pref[i - 1]);
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = suf[i + 1] + a[i];
    }
    for (int k = 1; k < n; ++k) {
        long long x = suf[n - k + 1], y = suf[n - k + 2] + pref[n - k];
        std::cout << (y > x ? y : x) << ' ';
    }
    std::cout << suf[1] << '\n';
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
