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
 * Created: Jan 19, 2025 @ 16:23:26
 * Author: will_wang
 */
void solve() {
    int n;
    std::cin >> n;
    if (n % 2 == 1) {
        std::cout << -1 << '\n';
        return;
    }
    std::vector<int> ans(n);
    std::iota(ans.begin(), ans.end(), 1);
    for (int i = 0; i < n; i += 2) {
        std::swap(ans[i], ans[i + 1]);
    }
    for (int i = 0; i < (int) ans.size(); ++i) {
        std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;
    for (int i = 0; i < t; ++i) {
        // std::cout << "Case #" << (i + 1) << ": ";
        solve();
    }
}
