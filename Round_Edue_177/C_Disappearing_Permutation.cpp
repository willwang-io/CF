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

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> p(n + 1), d(n);
    FOR(i, 1, n + 1, 1) { std::cin >> p[i]; }
    FOR(i, 0, n, 1) { std::cin >> d[i]; }

    std::vector<int> cycle(n + 1), sz, seen(n + 1);
    long long cycle_cnt = 0, total = 0;
    FOR(i, 1, n + 1, 1) {
        if (!seen[i]) {
            int cur = i, cnt = 0;
            std::vector<int> nodes;
            while (!seen[cur]) {
                seen[cur] = 1;
                nodes.push_back(cur);
                ++cnt;
                cur = p[cur];
            }
            sz.push_back(cnt);
            total += cnt;
            ++cycle_cnt;
            EACH(x, nodes) {
                cycle[x] = cycle_cnt;
            }
        }
    }
    std::vector<long long> no(n + 1), a(cycle_cnt + 1, 1);
    EACH(x, d) {
        if (!no[x]) {
            no[x] = 1;
            int y = cycle[x];
            if (y && a[y]) {
                total -= sz[y - 1];
                a[y] = 0;
            }
        }
        std::cout << n - total << ' ';
    }
    std::cout << '\n';
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
