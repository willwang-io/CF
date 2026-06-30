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
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(k, n));
    for (int i = n - 1; i >= 0; --i) {
        a[i] = a[i + 1];
        a[i][s[i] - 'a'] = i;
    }
    std::vector<int> b(n + 1, n + 1);
    b[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int c = 0; c < k; ++c) {
            b[i] = std::min(b[i], (a[i][c] == n ? 1 : 1 + b[a[i][c] + 1]));
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        std::string t;
        std::cin >> t;
        int i = 0;
        for (auto &c: t) {
            int j = a[i][c - 'a'];
            if (j == n) {
                i = -1;
                break;
            }
            i = j + 1;  
        }
        std::cout << (i == -1 ? 0 : b[i]) << '\n';
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
