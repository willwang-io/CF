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
    int n, k;
    long long x;
    std::cin >> n >> k >> x;
    std::vector<long long> a(n), p(n);
    long long sum = 0;
    REP(i, n) {
        std::cin >> a[i];
        sum += a[i];
        if (i == 0) p[i] = 0;
        else p[i] = p[i - 1] + a[i - 1];
    }
    if (sum * k < x) {
        std::cout << 0 << '\n';
        return;
    }
    long long ans = 0;
    REP(i, k) {
        long long r = sum * (k - i) - x;
        if (r < 0) break;
        ans += std::upper_bound(p.begin(), p.end(), r) - p.begin();
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}
