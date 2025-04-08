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

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    REP(i, n) {
        std::cin >> a[i];
    }
    std::vector<bool> ok(n);
    int mx = 0;
    REP(i, m) {
        int cnt = 0;
        REP(j, n) {
            std::string s;
            std::cin >> s;
            if (s == a[j]) {
                ++cnt;
                ok[j] = true;
            }
        }
        mx = std::max(mx, cnt);
    }
    REP(i, n) {
        if (!ok[i]) {
            std::cout << "-1\n";
            return;
        }
    }
    std::cout << (mx != n ? 3 * n - 2 * mx : n) << '\n';
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
