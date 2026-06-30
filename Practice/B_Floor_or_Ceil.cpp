#include <map>
#include <bit>
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
 * Created: Mar 27, 2025 @ 17:25:22
 * Author: will_wang
 */
int mx(int x, int n, int m) {
    while (x && n) {
        x = x / 2;
        --n;
    }
    while (x > 1 && m) {
        x = x / 2 + (x % 2);
        --m;
    }
    return x;
}

int mn(int x, int n, int m) {
    while (x > 1 && m) {
        x = x / 2 + (x % 2);
        --m;
    }
    while (x && n) { 
        x = x / 2;
        --n;
    }
    return x;
}

void solve() {
    int x, n, m;
    std::cin >> x >> n >> m;
    std::cout << mn(x, n, m) << ' ' << mx(x, n, m) << '\n';
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
