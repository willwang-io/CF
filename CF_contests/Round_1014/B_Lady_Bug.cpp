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
 * Created: Mar 29, 2025 @ 08:39:18
 * Author: will_wang
 */
void solve(){
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (a[i] - '0') {
                ++cnt1;
            }
        } else {
            if (a[i] - '0') {
                ++cnt2;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (b[i] - '0') {
                ++cnt2;
            }
        } else {
            if (b[i] - '0') {
                ++cnt1;
            }
        }
    }
    if (n % 2 == 0){
        std::cout << ((cnt1 <= n / 2 && cnt2 <= n / 2) ? "YES\n" : "NO\n");
    } else {
        std::cout << ((cnt1 <= n / 2 && cnt2 <= (n + 1) / 2) ? "YES\n" : "NO\n");
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
