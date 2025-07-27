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

void solve() {
    int n;
    long long c;
    std::cin >> n >> c;
    std::vector<int> d;
    for (int i = 0; i < n; ++i) {
        long long a;
        std::cin >> a;
        long long x = c / a;
        d.push_back(x ? 63 - __builtin_clzll(x) : -1);
    }
    std::sort(d.begin(), d.end());
    int cnt = 0;
    for (auto di : d) {
        if (di >= cnt) {
            ++cnt;
        }
    }
    std::cout << (n - cnt) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}
