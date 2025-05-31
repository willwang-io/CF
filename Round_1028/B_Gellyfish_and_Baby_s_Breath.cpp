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

const int MOD = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> q[i];
    }
    std::vector<int> pow2(n);
    pow2[0] = 1;
    for (int i = 1; i < n; ++i) {
        pow2[i] = (int) ((pow2[i - 1] * 2LL) % MOD);
    }
    std::vector<int> ans(n);
    int P = p[0], idxP = 0, Q = q[0], idxQ = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            if (p[i] > P) {
                P = p[i];
                idxP = i;
            }
            if (q[i] > Q) {
                Q = q[i];
                idxQ = i;
            }
        }
        int m1 = q[i - idxP];
        int m2 = p[i - idxQ];
        int m = P > Q ? m1 : Q > P ? m2 : (m1 > m2 ? m1 : m2);
        ans[i] = (pow2[P > Q ? P : Q] + pow2[m]) % MOD;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << ' ';
    }
    std::cout << "\n";
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
