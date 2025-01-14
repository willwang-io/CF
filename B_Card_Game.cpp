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
 * Created: Jan 13, 2025 @ 20:34:40
 * Author: will_wang
 */
int check(int a1, int a2, int b1, int b2) {
    int ans = 0;
    if (a1 > b1 && a2 > b2) {
        ++ans;
    }
    if (a1 > b2 && a2 > b1) {
        ++ans;
    }
    dbg(ans);
    return ans;
}

void solve() {
    int a1, a2, b1, b2;
    std::cin >> a1 >> a2 >> b1 >> b2;
    int ans = 0;
    if (a1 > b1 && a2 > b2) {
        ++ans;
    }
    if (a1 > b2 && a2 > b1) {
        ++ans;
    }
    if (a2 > b1 && a1 > b2) {
        ++ans;
    }
    if (a2 > b2 && a1 > b1) {
        ++ans;
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
