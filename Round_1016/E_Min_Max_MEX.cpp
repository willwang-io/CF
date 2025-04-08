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
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class... Args> void dbg_out(T &&x, Args&&... args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    REP(i, n) {
        std::cin >> a[i];
    }
    auto ok = [&](int x) -> bool {
        int tmp = 0, y = 0;
        std::vector<int> b(x, 0);
        REP(i, n) {
            if (a[i] < x) {
                if (++b[a[i]] == 1) {
                    ++y;
                }
            }
            if (x == y) {
                if (++tmp >= k) {
                    return true;
                }
                y = 0;
                b.assign(x, 0);
            }
        }
        return tmp >= k;
    };
    int left = 0, right = n + 1, ans = 0;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (ok(mid)) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid;
        }
    }
    std::cout << ans << '\n';
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

