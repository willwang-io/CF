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
 * Created: Jan 12, 2025 @ 08:40:08
 * Author: will_wang
 */
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    long long sum_a = 0LL, sum_b = 0LL;
    for (auto &x: a) {
        std::cin >> x;
        sum_a += x;
    }
    for (auto &x: b) {
        std::cin >> x;
        sum_b += x;
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (b[i] > a[i]) {
            int needed = b[i] - a[i];
            bool found = false;
            for (int j = 0; j < n; ++j) {
                if (i != j && a[j] - b[j] >= needed) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                ok = false;
                break;
            }
        }
    }
    std::cout << (ok ? "YES\n" : "NO\n"); 
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
