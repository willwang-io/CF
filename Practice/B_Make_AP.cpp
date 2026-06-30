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
   long long a, b, c;
   std::cin >> a >> b >> c; 
   if (std::abs(b - a) == std::abs(c - b)) {
       std::cout << "YES\n";
       return;
   }
   if ((2 * b - c > 0 && (2 * b - c) % a == 0) || (2 * b - a > 0 && (2 * b - a) % c == 0)) {
       std::cout << "YES\n";
       return;
   }
   if ((c - a) % 2 == 0) {
       if ((c + a) % (2 * b) == 0) {
           std::cout << "YES\n";
           return;
       }
   }
   std::cout << "NO\n";
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
