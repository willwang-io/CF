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
 * Created: Jan 16, 2025 @ 13:07:56
 * Author: will_wang
 */

const int MAX_N = 1e5 + 1;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> sieve(MAX_N, 0);
    std::iota(sieve.begin(), sieve.end(), 0);

    for (int i = 2; i < MAX_N; ++i) {
        if (sieve[i] != i) {
            continue;
        }
        for (int j = i; j < MAX_N; j += i) {
            sieve[j] = std::min(sieve[j], i);
        }
    }
    std::vector<int> primes;
    for (int i = 2; i < MAX_N; ++i) {
        if (sieve[i] == i) {
            primes.push_back(i);
        }
    }
    std::cout << (n >= 3 ? 2 : 1) << '\n';
    for (int i = 2; i <= n + 1; ++i) {
        std::cout << (sieve[i] == i ? 1 : 2) << ' ';
    }
    std::cout << '\n';
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
