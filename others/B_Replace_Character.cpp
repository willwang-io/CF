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
 * Created: Jan 17, 2025 @ 13:02:47
 * Author: will_wang
 */
void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> cnt(26);
    for (auto &c: s) {
        ++cnt[c - 'a'];
    }
    int mx = *std::max_element(cnt.begin(), cnt.end());
    int mn = 1e9;
    char mx_c, mn_c;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] == 0) {
            continue;
        }
        if (cnt[i] == mx) {
            mx_c = i + 'a';
        }
        if (cnt[i] < mn) {
            mn = cnt[i];
            mn_c = i + 'a';
        }
    }
    for (auto &c: s) {
        if (c == mn_c) {
            c = mx_c;
            break;
        }
    }
    std::cout << s << '\n';
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
