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

#define EACH(x, a) for (auto& x: a)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class...Args> void dbg_out(T &&x, Args&&...args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

long long a(long long n, long long x, long long y) {
    if (n == 1) {
        if (!x && !y) {
            return 1;
        }
        if (x == 1 && y == 1) {
            return 2;
        }
        if (x == 1 && !y) {
            return 3;
        }
        return 4;
    }
    long long h = 1 << (n - 1);
    if (x < h && y < h) {
        return a(n - 1, x, y);
    }
    if (x >= h && y >= h) {
        return h * h + a(n - 1, x - h, y - h);
    }
    if (x >= h && y < h) {
        return 2 * h * h + a(n - 1, x - h, y);
    }
    return 3 * h * h + a(n - 1, x, y - h);
}

std::pair<long long, long long> b(long long n, long long d) {
    if (n == 1) {
        if (d == 1) {
            return std::make_pair(0, 0);
        }
        if (d == 2) {
            return std::make_pair(1, 1);
        }
        if (d == 3) {
            return std::make_pair(1, 0);
        }
        return std::make_pair(0, 1);
    }
    long long h = 1 << (n - 1);
    if (d <= h * h) {
        return b(n - 1, d);
    }
    if (d <= 2 * h * h) {
        auto [x, y] = b(n - 1, d - h * h);
        return std::make_pair(x + h, y + h);
    }
    if (d <= 3 * h * h) {
        auto [x, y] = b(n - 1, d - 2 * h * h);
        return std::make_pair(x + h, y);
    }
    auto [x, y] = b(n - 1, d - 3 * h * h);
    return std::make_pair(x, y + h);
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    while (q--) {
        std::string s;
        std::cin >> s;
        if (s == "->") {
            long long x, y;
            std::cin >> x >> y;
            std::cout << a(n, x - 1, y - 1) << '\n';
        } else {
            long long d;
            std::cin >> d;
            auto [x, y] = b(n, d);
            std::cout << x + 1 << ' ' << y + 1 << '\n';
        }
    }
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
