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
    std::string s;
    std::cin >> s;
    for (int j = 0; j < n; ++j) {
        if (s[j] == 'B') {
            continue;
        }
        int i = j + 1;
        bool ok  = false;
        for (int k = 0; k < n; ++k) {
            if (s[k] == 'B') {
                int j = k + 1;
                if (!(i == 1 && j == n) && (j > i || (i == n && j == 1))) {
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) {
            std::cout << "Alice\n";
            return;
        }
    }
    std::cout << "Bob\n";
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
