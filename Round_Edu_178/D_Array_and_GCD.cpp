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

static const int MAXV = 6000000;
int spf[MAXV + 1];
std::vector<long long> primes_psum = {0};

void sieve() {
    for (int i = 2; i <= MAXV; ++i) {
        if (spf[i] == 0) {
            for (int j = i; j <= MAXV; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
        }
    }
    primes_psum.reserve(400000 + 5);
    for (int i = 2; i <= MAXV && (int) primes_psum.size() <= 400000; ++i) {
        if (spf[i] == i) {
            primes_psum.push_back(primes_psum.back() + i);
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::vector<long long> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (pref[i] >= primes_psum[i]) {
            mx = i;
        } else {
            break;
        }
    }
    std::cout << (n - mx) << '\n';
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
