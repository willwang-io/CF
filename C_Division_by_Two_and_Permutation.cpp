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
 * Created: Jan 15, 2025 @ 20:05:21
 * Author: will_wang
 */
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x: a) {
        std::cin >> x;
    }
    std::sort(a.rbegin(), a.rend());
    std::vector<int> seen(n + 1);
    for (int i = 0; i < n; ++i) {
        while (a[i] > n || seen[a[i]]) {
            a[i] /= 2;
        }
        if (a[i] > 0) {
            seen[a[i]] = 1;
        } else {
            std::cout << "NO\n";
            return;
        }
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
