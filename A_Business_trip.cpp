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
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int k;
    std::cin >> k;
    if (!k) {
        std::cout << 0 << '\n';
        return 0;
    }
    std::vector<int> a(12);
    for (auto &x: a) { std::cin >> x; }
    std::sort(a.rbegin(), a.rend());
    int cur = 0;
    for (int i = 0; i < 12; ++i) {
        cur += a[i];
        if (cur >= k) {
            std::cout << (i + 1) << '\n';
            return 0;
        }
    }
    std::cout << -1 << '\n';
}
