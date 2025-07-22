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

const int MOD = 998244353;

long long modpow(long long a, long long e) {
    long long ans = 1;
    a % MOD;
    while (e) {
        if (e & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        e >>= 1;
    }
    return ans;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> seg(m + 1);
    long long b = 1;
    for (int i = 0; i < n; ++i) {
        long long l, r, p, q;
        std::cin >> l >> r >> p >> q;
        long long diff = (q - p + MOD) % MOD;
        b = b * (diff * modpow(q, MOD - 2) % MOD) % MOD;
        seg[r].emplace_back(l, (p % MOD * modpow(diff, MOD - 2) % MOD));
    }
    std::vector<long long> dp(m + 1, -1);
    dp[0] = 1;
    std::function<long long(int)> dfs = [&](int j) {
        if (dp[j] != -1) {
            return dp[j];
        }
        long long tmp = 0;
        for (auto &[l, r]: seg[j]) {
            tmp = (tmp + dfs(l - 1) * r) % MOD;
        }
        return dp[j] = tmp;
    };
    std::cout << (b * dfs(m) + MOD) % MOD << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = 1;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}
