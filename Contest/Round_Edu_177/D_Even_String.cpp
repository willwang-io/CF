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

#define EACH(x, a) for (auto& x: a)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class...Args> void dbg_out(T &&x, Args&&...args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

const long long MOD = 998244353, MAXN = 5e5 + 1;
std::vector<long long> f(MAXN + 1);

long long pow_mod(long long b, long long e) {
    long long res = 1;
    while (e > 0) {
        if (e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return res;
}

void solve() {
    std::vector<int> cnt(26);
    int n = 0;
    REP(i, 26) {
        std::cin >> cnt[i];
        n += cnt[i];
    }
    int odd = (n + 1) / 2, even = n / 2, t = 2;
    std::vector<int> seen(n + 1), dp(n + 1);
    seen[0] = t;
    dp[0] = 1;
    REP(i, 26) {
        int x = cnt[i];
        if (!x) {
            continue;
        }
        RFOR(j, n, x, 1) {
            if (seen[j - x] == t) {
                if (seen[j] != t) {
                    dp[j] = 0;
                    seen[j] = t;
                }
                dp[j] = (dp[j] + dp[j - x]) % MOD;
            }
        }
    }

    long long x = seen[odd] == t ? dp[odd] : 0, tmp = 1;
    REP(i, 26) {
        if (cnt[i] > 0) {
            tmp = (tmp * f[cnt[i]]) % MOD;
        }
    }
    std::cout << ((((f[odd] * f[even] % MOD) * pow_mod(tmp, MOD - 2) % MOD) * x) % MOD) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    f[0] = 1;
    FOR(i, 1, MAXN, 1) {
        f[i] = f[i - 1] * i % MOD;
    }

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        // std::cout << "Case #" << (i + 1) << ": ";
        solve();
    }
}
