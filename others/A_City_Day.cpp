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
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<long long> a(n);
    REP(i, n) {
        std::cin >> a[i];
    }
    REP(i, n) {
        long long left = 1e18, right = 1e18;
        FOR(j, i + 1, std::min(i + y + 1, n), 1) {
            left = std::min(left, a[j]);
        }
        FOR(j, i - 1, std::max(i - x - 1, -1), -1) {
            right = std::min(right, a[j]);
        }
        if (a[i] < left && a[i] < right) {
            std::cout << i + 1 << '\n';
            return 0;
        }
    }
}
