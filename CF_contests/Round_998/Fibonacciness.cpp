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
 * Created: Jan 19, 2025 @ 08:35:28
 * Author: will_wang
 */
void solve() {
    int a1, a2, a4, a5;
    std::cin >> a1 >> a2 >> a4 >> a5;
    int ans = 0;
    std::vector<int> a = {a1, a2, 0, a4, a5};
    for (int a3 = -1000; a3 < 1000; ++a3) {
        a[2] = a3;
        int cur = 0;
        for (int i = 0; i < 3; ++i) {
            if (a[i + 2] == a[i] + a[i + 1]) {
                ++cur;
            }
        }
        ans = std::max(ans, cur);
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
