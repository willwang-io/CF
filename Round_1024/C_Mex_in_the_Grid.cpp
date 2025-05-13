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
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int val = n * n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            a[top][i] = val--;
        }
        ++top;
        for (int i = top; i <= bottom; ++i) {
            a[i][right] = val--;
        }
        --right;
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                a[bottom][i] = val--;
            }
            --bottom;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                a[i][left] = val--;
            }
            ++left;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
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
