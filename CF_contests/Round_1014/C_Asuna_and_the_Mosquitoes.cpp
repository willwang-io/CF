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
 * Created: Mar 29, 2025 @ 08:41:35
 * Author: will_wang
 */
const long long INF = 1e18;

void solve(){
    int n;
    std::cin >> n;
    long long total = 0, mx = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        long long x;
        std::cin >> x;
        total += x;
        mx = std::max(mx, x);
        cnt += (x & 1);
    }
    if (cnt == 0 || cnt == n){
        std::cout << mx << "\n";
        return;
    }
    long long tmp1 = total - (cnt - 1), tmp2 = total - cnt;
    if (tmp1 % 2 == 0) {
        --tmp1;
    }
    if (tmp2 % 2 == 1) {
        --tmp2;
    }
    std::cout << std::max(tmp1, tmp2) << "\n";
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
