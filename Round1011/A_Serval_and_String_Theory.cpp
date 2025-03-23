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
 * Created: Mar 22, 2025 @ 08:35:59
 * Author: will_wang
 */
void solve() {
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;
    bool ok = true;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[0]) {
            ok = false;
            break;
        }
    }
    auto tmp = s;
    std::reverse(tmp.begin(), tmp.end());
    if (s < tmp) {
        std::cout << "YES\n";
    } else if (ok) {
        std::cout << "NO\n";
    } else if (k > 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
