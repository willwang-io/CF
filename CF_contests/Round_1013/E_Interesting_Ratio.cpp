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
 * Created: Mar 25, 2025 @ 08:53:24
 * Author: will_wang
 */
const int MAX_N = 10000000;
int p[MAX_N + 1];

void sieve() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!p[i]) {
            for (int j = i; j <= MAX_N; j += i) {
                if (!p[j]) p[j] = i;
            }
        }
    }
}
void solve() {
    long long n;
    std::cin >> n;
    long long ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (p[i] == i) {
            ans += n / i;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        // std::cout << "Case #" << (i + 1) << ": ";
        solve();
    }
}
