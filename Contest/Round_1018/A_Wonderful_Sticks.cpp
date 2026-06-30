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
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> mn, mx;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<') {
            mn.push_back(i + 2);
        } else {
            mx.push_back(i + 2);
        }
    }
    int p = (int) mn.size(), q = (int) mx.size();
    std::vector<int> ans(n + 1);
    ans[1] = p + 1;
    for (int i = 0; i < p; ++i) {
        ans[mn[i]] = p - i;
    }
    for (int i = 0; i < q; ++i) {
        ans[mx[i]] = p + i + 2;
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
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
